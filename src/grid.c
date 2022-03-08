/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   grid.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 19:28:56 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/08 19:04:04 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/hexathon.h"

char	**ft_setup_grid(void)
{
	char	**array;
	int		i;
	int		j;

	array = calloc(1000, 1);
	j = 0;
	while (j < 9)
	{
		if (j == 0)
			array[j] = "abcde";
		if (j == 1)
			array[j] = "aabcde";
		if (j == 2)
			array[j] = "aaabcde";
		if (j == 3)
			array[j] = "aaaabcde";
		if (j == 4)
			array[j] = "aaaaabcde";
		if (j == 5)
			array[j] = "aaaabcde";
		if (j == 6)
			array[j] = "aaabcde";
		if (j == 7)
			array[j] = "aabcde";
		if (j == 8)
			array[j] = "abcde";
		j++;
	}
	return (array);
}

int	ft_total_size_grid(t_vari *data)
{
	int	length;
	int	length_2;
	int	count;

	length = data->size;
	length_2 = length;
	count = 1;
	while (count < length_2 - 1)
	{
		length += length_2 + count;
		count++;
	}
	length *= 2;
	length += length_2 * 2 - 1;
	return (length);
}

char	**ft_grid(t_vari *data)
{
	int		total_size;
	char	**grid;

	total_size = ft_total_size_grid(data);
	//printf("size : %d\n", total_size);
	if (total_size == 61)
	{
		grid = ft_setup_grid();
	}
	return (grid);
}
