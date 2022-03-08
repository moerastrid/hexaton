/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 16:18:27 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/08 15:26:54 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/hexathon.h"

int	main(void)
{
	t_vari		data;
	mlx_t		*mlx;
	mlx_image_t	*img;

	data.shape = 0;
	data.size = 5;
	data.colors = 2;
	data.figure = 0;
	data.grid = ft_grid(&data);
	mlx = mlx_init(WIDTH, HEIGHT, "hexathon", false);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx_image_to_window(mlx, img, 0, 0, 0);
	ft_draw(data, img);
	mlx_loop(mlx);
	ft_stop(mlx);
	free(data.grid);
	return (0);
}
