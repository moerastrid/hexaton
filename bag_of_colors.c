#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

// hex grid 5 -> 61 hex squares
// amount of color chips (61/16) * 4 = 12 (per player)
// equal distribution of color chips? (for now, yes!)

typedef struct s_vari
{
	int	size;
	int	colors;
	int	shape;
	int	figure;
}		t_vari;

typedef struct s_player
{
	char tile_set[13];
	char tile1;
	char tile2;
}	t_player;

char	random_tile_grabber(t_player *tiles, char player)
{
	char ret;
	int upper = 12;
	int lower = 0;
	if (player == '1')
	{
		size_t len = strlen(tiles->tile_set);
		if (len == 0) /* We are all out of characters */
			return (-1);
		/* Select a character at random */
		int rv = (rand() % (upper - lower + 1)) + lower;
		printf("Random (?) number: %i\n", rv);
		ret = tiles->tile_set[rv];
		tiles->tile_set[rv] = 'X';
		/* Remove the selected character from the set */ 
		tiles->tile_set[rv] = tiles->tile_set[len - 1];
		tiles->tile_set[len - 1] = '\0';
		/* Return the character */
		return (ret);
	}
	else
		return('X');
}

int main(void)
{
	//2 random from purple and blue
	//2 random form red and orange
	t_player tiles;
	char player = '1';
	strcpy(tiles.tile_set, "ppppppbbbbbb");
	srand(time(0));
	tiles.tile1 = random_tile_grabber(&tiles, player);
	tiles.tile2 = random_tile_grabber(&tiles, player);
	printf("Tile 1 is: %c\nTile 2 is: %c\n", tiles.tile1, tiles.tile2);
}
