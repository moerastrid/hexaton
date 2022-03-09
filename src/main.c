#include "../include/hexathon.h"
#include <stdio.h>

int		main(int argc, char *argv[])
{
	t_vari		data;
	mlx_t		*mlx;
	mlx_image_t	*img;

	data.shape = 0;
	//data.size = SIDE;
	data.size = 9;
	data.colors = 2;
	data.figure = 0;
	data.max_tiles = (3 * (data.size * data.size)) - (3 * data.size) + 1;
	data.max_colors = (data.max_tiles / 16) * 4;
	data.grid = ft_grid(&data);
	ft_create_bags_of_colors(&data);
	ft_picking_tiles(&data, 1); //player 1, 2 tiles
	// ft_picking_tiles(&data, 2); //player 2, 2 tiles
	mlx = mlx_init(WIDTH, HEIGHT, "hexathon", false);
	img = mlx_new_image(mlx, mlx->width, mlx->height);
	data.mlx = mlx;
	data.img = img;
	ft_convert(&data);
	ft_draw(&data, img);
	mlx_image_to_window(mlx, img, 0, 0, 0);
	mlx_key_hook(mlx, ft_keypress, &data);
	mlx_loop(mlx);

	// int i;

	// i = 0;
    // printf("%d\n",argc);
    // while (i < argc)
    // {
    //     printf("%s\n", argv[i]);
	// 	i++;
    // }
    // if (argc != 3)
    // {
    //     printf("Usage: %s <player1_exe> <player2_exe>\n", argv[0]);
    //     return 1;
    // }
	// return (0);
}
