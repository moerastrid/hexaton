#include <stddef.h>
#include <stdio.h>
#include "../include/hexathon.h"

char	random_tile_grabber1(t_vari *data)
{
	char ret;
	data->max_tiles = ((61 / 16 ) * 4);
	int upper = data->max_tiles;
	int lower = 0;

	size_t len = strlen(data->player1.tile_set);
	if (len == 0) /* We are all out of characters */
		return (-1);
	/* Select a character at random */
	int rv = (arc4random() % (upper - lower + 1)) + lower;
	printf("Random (?) number: %i\n", rv);
	ret = data->player1.tile_set[rv];
	/* Remove the selected character from the set */ 
	data->player1.tile_set[rv] = data->player1.tile_set[len - 1];
	data->player1.tile_set[len - 1] = '\0';
	upper--; //reducing upper limit for using arc4random
	/* Return the character */
	printf("inside tile grabber: %c\n", ret);
	return (ret);
}

char	random_tile_grabber2(t_vari *data)
{
	char ret;
	data->max_tiles = ((61 / 16 ) * 4);
	int upper = data->max_tiles;
	int lower = 0;

	size_t len = strlen(data->player2.tile_set);
	if (len == 0) /* We are all out of characters */
		return (-1);
	/* Select a character at random */
	int rv = (arc4random() % (upper - lower + 1)) + lower;
	printf("Random (?) number: %i\n", rv);
	ret = data->player2.tile_set[rv];
	/* Remove the selected character from the set */ 
	data->player2.tile_set[rv] = data->player2.tile_set[len - 1];
	data->player2.tile_set[len - 1] = '\0';
	upper--; //reducing upper limit for using arc4random
	/* Return the character */
	printf("inside tile grabber: %c\n", ret);
	return (ret);
}

int ft_colorbag_player1(t_vari *data)
{
	// player 1: 2 random from purple and blue
	
	strcpy(data->player1.tile_set, "ppppppbbbbbb");
	printf("Tile set: %s\n", data->player1.tile_set);
	data->player1.tile1 = random_tile_grabber1(&data);
	data->player1.tile2 = random_tile_grabber1(&data);
	printf("Tile 1 is: %c\nTile 2 is: %c\n", data->player1.tile1, data->player1.tile2);
}

int ft_colorbag_player2(t_vari *data)
{
	// player 2: 2 random from red and orange
	
	strcpy(data->player2.tile_set, "rrrrrroooooo");
	printf("Tile set: %s\n", data->player2.tile_set);
	data->player2.tile1 = random_tile_grabber2(&data);
	data->player2.tile2 = random_tile_grabber2(&data);
	printf("Tile 1 is: %c\nTile 2 is: %c\n", data->player2.tile1, data->player2.tile2);
}
