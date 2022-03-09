/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   grid.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 19:28:56 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/09 11:15:06 by ageels        ########   odam.nl         */
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

// int	ft_total_size_grid(t_vari *data)
// {
// 	int	length;
// 	int	length_2;
// 	int	count;

// 	length = data->size;
// 	length_2 = length;
// 	count = 1;
// 	while (count < length_2 - 1)
// 	{
// 		length += length_2 + count;
// 		count++;
// 	}
// 	length *= 2;
// 	length += length_2 * 2 - 1;
// 	return (length);
// }

char	**ft_grid(t_vari *data)
{
	int		total_size;
	char	**grid;

	//total_size = ft_total_size_grid(data);
	//if (total_size == 61)
	grid = ft_setup_grid(data->size);
	//else
	//	printf("please change data->size to 5");
	return (grid);
}
