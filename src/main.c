/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 16:18:27 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/07 16:41:34 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headerfile.h"

void	ft_make_grid(t_vari *data)
{
	
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



