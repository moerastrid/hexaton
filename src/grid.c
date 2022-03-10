/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   grid.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 19:28:56 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/10 20:54:43 by bde-meij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/hexathon.h"

char	**ft_setup_grid(int side)
{
	int		i;
	int		j;
	char	**array;
	int		no_rows;
	int		curro;

	no_rows = (side * 2) - 1;
	curro = side;
	array = calloc(no_rows + 1, sizeof(char *));
	for (int j = 0; j < no_rows; j++)
	{
		char	*row;
		row = calloc(curro + 1, sizeof(char));
		array[j] = row;
		for (int i = 0; i < curro; i++)
		{
			row[i] = 'a';
		}
		if (j < side - 1)
			curro++;
		else
			curro--;
	}
	return (array);
}

char	**ft_grid(t_vari *data)
{
	return (ft_setup_grid(data->size));
}
