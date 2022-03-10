/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   makeoutput.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 00:06:52 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/11 00:06:53 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/hexathon.h"

char	*ft_convert_map(t_vari *data)
{
	char *temp;
	int tempi;

	tempi = 0;
	for (int j = 0; data->grid[j]; j++)
	{
		for (int i = 0; data->grid[j][i]; i++)
		{
			tempi++;
		}
	}

	temp = calloc(tempi + 1, sizeof(char));
	tempi = 0;
	for (int j = 0; data->grid[j]; j++)
	{
		for (int i = 0; data->grid[j][i]; i++)
		{
			temp[tempi] = data->grid[j][i];
			tempi++;
		}
	}
	return(temp);
}

char	*ft_makeoutput(t_vari *data)
{
	char *mapstring;
	char *side;
	char *inrow;
	char *time;
	int fd = 1;

	side = ft_itoa(SIDE);
	mapstring = ft_strdup(side);
	mapstring = ft_charjoin(mapstring, ',');
	free(side);
	inrow = ft_itoa(INROW);
	mapstring = ft_strjoin(mapstring, inrow);
	mapstring = ft_charjoin(mapstring, ',');
	free(inrow);
	time = ft_itoa(WAITTIME);
	mapstring = ft_strjoin(mapstring, time);
	mapstring = ft_charjoin(mapstring, ',');
	free(time);
	if (data->currentplayer == 1)
	{
	 	mapstring = ft_charjoin(mapstring, data->player1->tile1);
	 	mapstring = ft_charjoin(mapstring, data->player1->tile2);
		mapstring = ft_charjoin(mapstring, ',');
	}
	else if (data->currentplayer == 2)
	{
		mapstring = ft_charjoin(mapstring, data->player2->tile1);
		mapstring = ft_charjoin(mapstring, data->player2->tile2);
		mapstring = ft_charjoin(mapstring, ',');
	}
	mapstring = ft_strjoin(mapstring, ft_convert_map(data));
	mapstring = ft_charjoin(mapstring, '\n');
	return (mapstring);
}
