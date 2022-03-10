/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gameloop.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 00:05:43 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/11 00:05:44 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/hexathon.h"

void	gameloop(void *invar)
{
	t_loopdata	*loopdata;
	char		*myinput;

	loopdata = (t_loopdata *)invar;
	loopdata->data->currentplayer = ft_turn();
	if (loopdata->data->currentplayer == 1)
	{
		if(ft_picking_tiles(loopdata->data, 1) == -1) //player 1, 2 tiles
		{
			printf("player1 loses");
			mlx_close_window(loopdata->data->mlx);
		}
		dprintf(loopdata->player_bot1->stdin[1], "%s", ft_makeoutput(loopdata->data));
		sleep(WAITTIME);
		fscanf(loopdata->player_bot1->reader, "%s", &myinput);
		ft_convert_input(loopdata->data, &myinput);
	}
	if (loopdata->data->currentplayer == 2)
	{
		if(ft_picking_tiles(loopdata->data, 2) == -1) //player 2, 2 tiles
		{
			printf("player2 loses");
			mlx_close_window(loopdata->data->mlx);
		}
		dprintf(loopdata->player_bot2->stdin[1], "%s", ft_makeoutput(loopdata->data));
		sleep(WAITTIME);
		fscanf(loopdata->player_bot2->reader, "%s", &myinput);
		ft_convert_input(loopdata->data, &myinput);
	}
	ft_draw(loopdata->data, loopdata->hexagons);
	if (ft_win(loopdata->data) == true)
	{
		printf("player %d wins \n", loopdata->data->currentplayer);
		mlx_close_window(loopdata->data->mlx);
	}
}