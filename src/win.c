#include "../include/hexathon.h"
#include <stdio.h>

bool ft_checkbelow()
{

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
			if (ft_checkbelow() == true)
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