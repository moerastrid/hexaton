/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   grid.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 19:28:56 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/07 20:58:22 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/hexathon.h"

char	**ft_setup_grid(int total_size)
{
	void	*ptr_array;
	char	**datastart;
	int		pa_len;

	pa_len = 10;
	ptr_array = calloc(total_size + pa_len * sizeof(void *), sizeof(int));
	if (ptr_array == 0)
		return (NULL);
	datastart = ptr_array + pa_len;
	((char **)ptr_array)[0] = datastart;
	((char **)ptr_array)[1] = datastart + 5;
	((char **)ptr_array)[2] = datastart + 11;
	((char **)ptr_array)[3] = datastart + 18;
	((char **)ptr_array)[4] = datastart + 26;
	((char **)ptr_array)[5] = datastart + 35;
	((char **)ptr_array)[6] = datastart + 43;
	((char **)ptr_array)[7] = datastart + 50;
	((char **)ptr_array)[8] = datastart + 56;
	return ((char **)ptr_array);
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
	printf("size : %d\n", total_size);
	if (total_size == 61)
	{
		grid = ft_setup_grid(total_size);
	}
	return (grid);
}