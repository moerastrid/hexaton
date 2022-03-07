/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 16:18:27 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/07 16:57:30 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "hexathon.h"

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

void	ft_make_grid(t_vari *data)
{
	int	total_size;

	total_size = ft_total_size_grid(data);
	printf("%d", total_size);
}

int	main(void)
{
	t_vari	data;

	data.shape = 0;
	data.size = 5;
	data.colors = 2;
	data.figure = 0;
	ft_make_grid(&data);
	return (0);
}



