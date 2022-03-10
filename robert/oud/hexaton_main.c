/*
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include "hextaton.h"
#include <stdio.h>

int		main(int argc, char *argv[])
{
	int i;

	i = 0;
    printf("%d\n",argc);
    while (i < argc)
    {
        printf("%s\n", argv[i]);
		i++;
    }

    if (argc != 3)
    {
        printf("Usage: %s <player1_exe> <player2_exe>\n", argv[0]);
        return 1;
    }
//
//    player_t players[MAX_PLAYER] = {0};
//
//    for (int i = 0; i < MAX_PLAYER; i++)
//
//    {
//
//        init_player(argv[i+1], &players[i]);
//
//    }
//
//​
//
//    int winner = 0;
//
//    while (!winner)
//
//    {
//
//        //TURN FOR EACH PLAYER
//
//        //TODO : Create the game check if the move is legal / possible
//
//        //TODO Create the commands list/ protocol
//
//        //TODO Send the state of the game to the player
//
//        //TODO win condition
//
//        //TODO timeout for each player
//
//        //TODO everyhing else :D
//
//        //TODO Make the all thing safe enough so that the bot can crash without you crashing with it :D
//
//​
//
//        for (int i = 0; i < MAX_PLAYER; i++)
//
//        {
//
//            char* line = NULL;
//
//            size_t len = 0;
//
//            const player_t* player = &players[i];
//
//            //send board state to the player
//
//            dprintf(player->stdin[STDOUT_FILENO], "Player %d - game state very interesting\n", i);
//
//            //read player move from the pipes
//
//            getline(&line, &len, player->reader);
//
//            printf("Player %d - move: %s", i, line);
//
//            free(line);
//
//        }
//
//        winner = 1;//Ez game
//
//    }
//
    printf("Game over\n");

//    (void)players;

//}


	return (0);
}
