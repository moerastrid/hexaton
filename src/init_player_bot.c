/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_player_bot.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbeens <rbeens@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 00:06:13 by rbeens        #+#    #+#                 */
/*   Updated: 2022/03/11 00:06:26 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/hexathon.h"

int init_player(const char* path, player_bot_t* player)
{
    assert(player != NULL);
    int ret = pipe(player->stdin);
    ret += pipe(player->stdout);
    assert(ret == 0);
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }
    else if (pid == 0)
    {
        // Child process stdin/stdout  1/0 must be closed
        // the pipes becomes the stdin/stdout of the child process
        close(STDOUT_FILENO);
        close(STDIN_FILENO);
        close(player->stdin[STDOUT_FILENO]);//IN SO CLOSE OUT
        close(player->stdout[STDIN_FILENO]);//OUT SO CLOSE IN
        ret = dup2(player->stdin[STDIN_FILENO], STDIN_FILENO);
        if (ret == -1)
        {
            perror("dup2");
            exit(1);
        }
        ret = dup2(player->stdout[STDOUT_FILENO], STDOUT_FILENO);
        if (ret == -1 || ret != STDOUT_FILENO)
        {
            perror("dup2");
            exit(1);
        }
        //TODO: check if the player is valid executable path
        ret = execl(path, "", NULL);
        if (ret == -1)
        {
            perror("execl");
            exit(1);
        }
    }
    else
    {
        //Parent process save pids of the children
        player->pid = pid;
        //Close the pipes
        close(player->stdin[STDIN_FILENO]);//IN FOR PLAYER SO CLOSE IN 
        close(player->stdout[STDOUT_FILENO]);
        player->reader = fdopen(player->stdout[STDIN_FILENO], "r");
        if (player->reader == NULL)
        {
            perror("fdopen");
            exit(1);
        }
    }
    return 0;
}