/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   win.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 00:07:08 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/11 00:07:09 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/hexathon.h"

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
	if (i < 0 || j < 0 || j + 1 > ((data->size - 1) * 2))
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
	if (i < 0 || j < 0 || j + 1 > ((data->size - 1) * 2))
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

bool    ft_win(t_vari	*data)
{
    if (ft_wincheck(data))
    {
		return (true);
    }
	return(false);
}