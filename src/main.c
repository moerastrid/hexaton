/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 00:06:46 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/11 00:33:00 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/hexathon.h"

int		main(int argc, char *argv[])
{
	t_vari		data;
	t_loopdata	loopdata;
	mlx_t		*mlx;
	mlx_image_t	*img;
	mlx_texture_t *hexagons[] = {
		mlx_load_png("include/hexa.png"),
		mlx_load_png("include/hexb.png"),
		mlx_load_png("include/hexc.png"),
		mlx_load_png("include/hexd.png"),
		mlx_load_png("include/hexe.png"),
		mlx_load_png("include/game_over.png"),
	};

	if (argc != 3)
	{
		printf("Usage: %s <player1_exe> <player2_exe>\n", argv[0]);
		return (1);
	}
	if (SIDE > 10 || SIDE < 3)
	{
		printf("Please choose hexagon side size between 3 and 10");
		return (1);
	}
	if (INROW > 10 || INROW < 2)
	{
		printf("Please choose amount in a row between 2 and 10");
		return (1);
	}
	if (WAITTIME > 10 || WAITTIME < 1)
	{
		printf("Please choose waiting time between 1 and 10");
		return (1);
	}
	
	
	player_bot_t player_bot1;
	player_bot_t player_bot2;
	bzero(&player_bot1, sizeof(player_bot_t));
	bzero(&player_bot2, sizeof(player_bot_t));
	init_player(argv[1], &player_bot1);
	init_player(argv[2], &player_bot2);

	data.shape = 0;
	data.size = SIDE;
	data.colors = 2;
	data.figure = 0;
	data.max_tiles = (3 * (data.size * data.size)) - (3 * data.size) + 1;
	data.max_colors = (data.max_tiles / 16) * 4;
	data.grid = ft_grid(data.size);
	if(ft_create_bags_of_colors(&data) == -1)
	{
		printf(BAGERROR);
		ft_free_at_last(&data);
		return(0);
	}
	mlx = mlx_init(WIDTH, HEIGHT, "hexathon", false);
	img = mlx_new_image(mlx, mlx->width, mlx->height);
	data.mlx = mlx;
	data.img = img;
	ft_draw(&data, hexagons);
	mlx_image_to_window(mlx, img, 0, 0);
	loopdata.data = &data;
	loopdata.hexagons = hexagons;
	loopdata.player_bot1 = &player_bot1;
	loopdata.player_bot2 = &player_bot2;
	mlx_loop_hook(mlx, gameloop, &loopdata);
	mlx_key_hook(mlx, ft_keypress, &data);
	mlx_put_string(mlx, "choose:", 15, 20);
	if (ft_win(&data) == true)
	{
		mlx_remove_hook(data.mlx, gameloop);
	}
	mlx_loop(mlx);
	ft_free_at_last(&data);
	return (0);
}
