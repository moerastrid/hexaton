#include "../include/hexathon.h"
#include <stdio.h>

bool ft_checkbelow(int j, int i, t_vari *data, char currentc, int counter)
{
	if (currentc == 'a')
		return (false);
	if (i < 0 || j < 0)
		return (false);
	if (data->grid[j][i+1] == '\0' || data->grid[j][i] != data->grid[j][i+1])
		return (false);
	counter++;
	if (counter == INROW)
		return (true);
	return(ft_checkbelow(j, i+1, data, currentc, counter));
}

bool ft_checktoside(int j, int i, t_vari *data, char currentc, int counter)
{
	if (currentc == 'a')
		return (false);
	if (i < 0 || j < 0)
		return (false);
	if (j < (data->size - 1))
	{
		if (data->grid[j+1][i] == '\0' || data->grid[j][i] != data->grid[j+1][i])
			return (false);
	}
	else
	{
		if (data->grid[j+1][i-1] == '\0' || data->grid[j][i] != data->grid[j+1][i-1])
			return (false);
	}
	counter++;
	if (counter == INROW)
		return (true);
	if (j < (data->size - 1))
		return(ft_checktoside(j++, i, data, currentc, counter));
	return(ft_checktoside(j++, i--, data, currentc, counter));
}

bool ft_checkotherside(int j, int i, t_vari *data, char currentc, int counter)
{
	if (currentc == 'a')
		return (false);
	if (i < 0 || j < 0)
		return (false);
	if (j >= (data->size - 1))
	{
		if (data->grid[j+1][i] == '\0' || data->grid[j][i] != data->grid[j+1][i])
			return (false);
	}
	else
	{
		if (data->grid[j+1][i-1] == '\0' || data->grid[j][i] != data->grid[j+1][i-1])
			return (false);
	}
	counter++;
	if (counter == INROW)
		return (true);
	if (j >= (data->size - 1))
		return(ft_checkotherside(j++, i, data, currentc, counter));
	return(ft_checkotherside(j++, i--, data, currentc, counter));
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
				return (true);
			if (ft_checktoside(j, i, data, data->grid[j][i], counter) == true)
				return (true);
			if (ft_checkotherside(j, i, data, data->grid[j][i], counter) == true)
				return (true);
			
        }
    }
    return(false);
}

void    ft_win(t_vari	*data)
{
    data->grid[1][0] = 'c';
	data->grid[2][1] = 'c';
    data->grid[1][2] = 'c';
	//data->grid[2][2] = 'c';
    data->grid[3][2] = 'c';
	data->grid[4][2] = 'c';
    ft_draw(data, data->img);
    if (ft_wincheck(data))
    {
        printf("you won!");
        //mlx_close_window(data->mlx);
    }
}