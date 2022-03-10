/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_stuff.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 14:09:14 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/03/10 14:14:44 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/hexathon.h"

static char	**ft_free_array(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}

void	ft_free_at_last(t_vari *data)
{
	data->grid = ft_free_array(data->grid);
	free(data->player1->tile_set);
	free(data->player2->tile_set);
	free(data->player1);
	free(data->player2);
}
