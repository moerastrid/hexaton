#include "../include/hexathon.h"
#include <stdio.h>

bool ft_checkbelow(int j, int i, t_vari *data, char currentc, int counter)
{
	if (data->grid[j][i+1] == '\0' && data->grid[j][i] != data->grid[j][i+1])
		return (false);
	else
	{
		counter++;
		if (counter == INROW)
			return (true);
		else if (ft_checkbelow(j, i, data, data->grid[j][i], counter) == true))
			return (true);
		else
			return (false);
	}
}

bool    ft_wincheck(t_vari	*data)
{
	int ia;
	int ib;
	int ic;
    for(int j = 0; data->grid[j] != NULL; j++)
    {
        for(int i = 0; data->grid[j][i] != '\0'; i++)
        {
			int counter = 1;
			if (ft_checkbelow(j, i, data, data->grid[j][i], counter) == true)
			{
				return (true);
			}
        }
    }
    return(false);
}

void    ft_win(t_vari	*data)
{
    data->grid[1][0] = 'c';
	data->grid[1][1] = 'c';
    data->grid[1][2] = 'c';
    data->grid[3][2] = 'c';
	data->grid[4][2] = 'c';
    ft_draw(data, data->img);
    if (ft_wincheck(data))
    {
        printf("you won!");
        //mlx_close_window(data->mlx);
    }
}