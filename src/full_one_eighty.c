#include "../include/hexathon.h"

void		full_one_eighty(char **grid, int size)
{
	int		x_length;
	int 	y_length;
	int 	a = 0;
	int 	b = 0;
	int		i = 0;
	char	c;

	x_length = (size * 2) - 2;
	y_length = size - 1;
	while (a < x_length)
	{
		while (grid[a][b] == 'a')
			b++;
		while (b < (y_length - i))
		{
			c = grid[a][y_length - i];
			grid[a][y_length - i] = grid[a][b];
			grid[a][b] = c;
			i++;
			b++;
		}
		if (a < (x_length / 2))
			y_length++;
		else
			y_length--;
		b = 0;
		i = 0;
		a++;	
	}
	a = 0;
	y_length = size - 1;
	while (a < y_length)
	{
		i = y_length + a;
		while (i > -1)
		{
			c = grid[a][i];
			grid[a][i] = grid[x_length - a][i];
			grid[x_length - a][i] = c;
			i--;
		}
		a++;
	}
}
