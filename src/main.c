/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 16:18:27 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/07 17:41:14 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "hexathon.h"

void	ft_setup_grid(void)
{
	char	**mygrid;
	void	*start;
	int		x;
	int		y;

	&start = mygrid + 10 * sizeof (char *);
	mygrid = calloc(61 + 10 * sizeof (char *), sizeof(char));

	y = 0;
	while(y != 9)
	{
		x = 0;
		while(x != 9)
		{
			if (y == 0)
				
			x++;
		}
		y++;
	}
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

void	ft_grid(t_vari *data)
{
	int	total_size;

	total_size = ft_total_size_grid(data);
	printf("%d", total_size);
	if (total_size == 61)
	{
		ft_setup_grid();
	}
}

int	main(void)
{
	t_vari	data;

	//data = ft_read_settings();
	data.shape = 0;
	data.size = 5;
	data.colors = 2;
	data.figure = 0;
	ft_grid(&data);
	return (0);
}
