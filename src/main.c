/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 16:18:27 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/09 11:32:47 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/hexathon.h"
#include <stdio.h>

int		main(int argc, char *argv[])
{
	t_vari		data;
	mlx_t		*mlx;
	mlx_image_t	*img;

	data.shape = 0;
	data.size = 8;
	data.colors = 2;
	data.figure = 0;
	data.grid = ft_grid(&data);
	ft_create_bag_of_colors(&data);
	data.player1.tile1 = random_tile_grabber1(&data);
	data.player1.tile2 = random_tile_grabber1(&data);
// choose function, if a tile is chosen the other goes back in bag. If no tile is chosen -> rotate
	mlx = mlx_init(WIDTH, HEIGHT, "hexathon", false);
	img = mlx_new_image(mlx, mlx->width, mlx->height);
	data.mlx = mlx;
	data.img = img;
	ft_draw(&data, img);
	mlx_image_to_window(mlx, img, 0, 0, 0);
	mlx_key_hook(mlx, ft_keypress, &data);
	mlx_loop(mlx);
	ft_stop(mlx);
	free(data.grid);

	int i;

	i = 0;
    printf("%d\n",argc);
    while (i < argc)
    {
        printf("%s\n", argv[i]);
		i++;
    }
    if (argc != 3)
    {
        printf("Usage: %s <player1_exe> <player2_exe>\n", argv[0]);
        return 1;
    }
	return (0);
}
