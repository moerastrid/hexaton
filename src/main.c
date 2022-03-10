#include "../include/hexathon.h"
#include <stdio.h>

int	ft_turn()
{
	static int	turncount = 0;
	
	if (turncount % 2 == 0)
	{
		turncount++;
		return (1);
	}
	turncount++;
	return (2);
}

void	ft_gameloop(t_vari *data, mlx_texture_t *hexagons[], player_bot_t *player_bot1, player_bot_t *player_bot2)
{
	char *myinput;

	data->currentplayer = ft_turn();
	printf("player %d\n", data->currentplayer);
	if (data->currentplayer == 1)
	{
		ft_picking_tiles(data, 1); //player 1, 2 tiles
		ft_makeoutput(data);
		char mijnstring[] = "hoi\n";
		dprintf(player_bot1->stdin[1], "%s", mijnstring);
		sleep(1);
		printf("Hola?\n");
		fscanf(player_bot1->reader, "%s", &myinput);
		printf("Hola2?\n");
		//ft_convert_input(data, myinput);
	}
	if (data->currentplayer == 2)
	{
		ft_picking_tiles(data, 2); //player 2, 2 tiles
		ft_makeoutput(data);
		char mijnstring[] = "hoi2\n";
		dprintf(player_bot2->stdin[1], "%s", mijnstring);
		sleep(1);
		fscanf(player_bot2->reader, "%s", &myinput);
		//ft_convert_input(data, myinput);
	}
	ft_draw(data, hexagons);
}

int		main(int argc, char *argv[])
{
	t_vari		data;
	mlx_t		*mlx;
	mlx_image_t	*img;
	mlx_texture_t *hexagons[] = {
		mlx_load_png("include/hexa.png"),
		mlx_load_png("include/hexb.png"),
		mlx_load_png("include/hexc.png"),
		mlx_load_png("include/hexd.png"),
		mlx_load_png("include/hexe.png"),
	};
	// if (argc != 3)
    // {
    //     printf("Usage: %s <player1_exe> <player2_exe>\n", argv[0]);
    //     return 1;
    // }
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
	data.grid = ft_grid(&data);
	ft_create_bags_of_colors(&data);
	mlx = mlx_init(WIDTH, HEIGHT, "hexathon", false);
	img = mlx_new_image(mlx, mlx->width, mlx->height);
	data.mlx = mlx;
	data.img = img;
	ft_draw(&data, hexagons);
	while (ft_win(&data) == false)
	{
		ft_gameloop(&data, hexagons, &player_bot1, &player_bot2);
	}
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_key_hook(mlx, ft_keypress, &data);
	mlx_put_string(mlx, "choose:", 15, 20);
	mlx_loop(mlx);

	ft_free_at_last(&data);
	return (0);
}
