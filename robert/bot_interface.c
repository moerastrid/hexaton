#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX_PLAYER 1

typedef struct s_player_bot
{
    pid_t pid;
    int stdin[2];
    int stdout[2];
    FILE* reader;
} player_bot_t;

//WARNING: This is a dirty EXAMPLE.
//       It is not safe and should not be used like this.
//       It is only here to give one idea of how to communicate with bots with something usable by any bot.
//       You can choose to use any other way - even hardcoded function ? 
//       You can use pipes, sockets, shared mem... you name it.
//       You will need to show and explain how bots will communicate with your game implementation.
// This example use pipes to communicate with bots.
// the good thing is with small modifications you can execute any kind of bots that can read stdin and write on stdout will work.
// being python / rust / C++ or whatever (not JS it's not a language you better use brainfuck...)

//+[----->+++<]>+.++++++++++++..----.+++.+[-->+<]>.-----------..++[->++<]>.+++++++.+++++++++++.[++>---<]>.--[-->+++++<]>--.-[--->+<]>.-[----->++<]>-.++++.[--->++++<]>-.--[--->+<]>.>+[--->++<]>++.----------.-[--->+<]>++.>-[--->+<]>.>++++++++++..


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
		printf("===========\n");
        printf("Player %s pid: %d\n", path, pid);
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

int main(int argc, const char* argv[])
{

//	printf("test");
    if (argc != 3)
    {
        printf("Usage: %s <player1_exe> <player2_exe>\n", argv[0]);
        return 1;
    }
    player_bot_t player;
	bzero(&player, sizeof(player_bot_t));
    init_player(argv[1], &player);
    init_player(argv[2], &player);

    int winner = 0;
    while (!winner)
    {
        //TURN FOR EACH PLAYER
        //TODO : Create the game check if the move is legal / possible
        //TODO Create the commands list/ protocol
        //TODO Send the state of the game to the player
        //TODO win condition
        //TODO timeout for each player
        //TODO everyhing else :D
        //TODO Make the all thing safe enough so that the bot can crash without you crashing with it :D

            char* line = NULL;
            size_t len = 0;
			int test;
            //send board state to the player
            dprintf(player.stdin[STDOUT_FILENO], "lalalal 6\n");
            //read player move from the pipes
			printf("===========\n");
			sleep(1);
            fscanf(player.reader, "%d", &test);
            printf("result %d\n", test);
            free(line);
        winner = 1;//Ez game
    }
    printf("Game over\n");
}
