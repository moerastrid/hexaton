/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bag_of_colors.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 10:45:38 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/03/10 22:05:58 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include "../include/hexathon.h"

int 	ft_picking_tiles(t_vari *data, int current_player)
{
	if (current_player == 1)
	{
		int upper = strlen(data->player1->tile_set);
		int lower = 0;

		// size_t len = strlen(data->player1->tile_set);
		if (upper == 0) /* We are all out of characters */
		{
			printf(EMPTYBAG);
			return (-1);
		}
		/* Select a character at random */
		int rv = (arc4random() % (upper - lower)) + lower;
		data->player1->tile1 = data->player1->tile_set[rv];
		/* Remove the selected character from the set */ 
		data->player1->tile_set[rv] = data->player1->tile_set[upper - 1];
		data->player1->tile_set[upper - 1] = '\0';
		upper = strlen(data->player1->tile_set); //reducing upper limit for using arc4random
		if (upper == 0) /* We are all out of characters */
		{
			printf(EMPTYBAG);
			return (-1);
		}
		/* Select a character at random */
		rv = (arc4random() % (upper - lower)) + lower;
		data->player1->tile2 = data->player1->tile_set[rv];
		/* Remove the selected character from the set */ 
		data->player1->tile_set[rv] = data->player1->tile_set[upper - 1];
		data->player1->tile_set[upper - 1] = '\0';
		return(0);
	}
	if (current_player == 2)
	{
	
		int upper = strlen(data->player2->tile_set);
		int lower = 0;

		// size_t len = strlen(data->player2->tile_set);
		if (upper == 0) /* We are all out of characters */
		{
			printf(EMPTYBAG);
			return (-1);
		}
		/* Select a character at random */
		int rv = (arc4random() % (upper - lower)) + lower;
		data->player2->tile1 = data->player2->tile_set[rv];
		/* Remove the selected character from the set */ 
		data->player2->tile_set[rv] = data->player2->tile_set[upper - 1];
		data->player2->tile_set[upper - 1] = '\0';
		upper = strlen(data->player2->tile_set); //updating upper limit for using arc4random
		if (upper == 0) /* We are all out of characters */
		{
			printf(EMPTYBAG);
			return (-1);
		}
		/* Select a character at random */
		rv = (arc4random() % (upper - lower)) + lower;
		data->player2->tile2 = data->player2->tile_set[rv];
		/* Remove the selected character from the set */ 
		data->player2->tile_set[rv] = data->player2->tile_set[upper - 1];
		data->player2->tile_set[upper - 1] = '\0';
		return(0);
	}
	else
	{
		printf("There is no current player... kind of gamebreaking\n");
		return(-1);
	}
}

int	ft_create_bags_of_colors(t_vari *data)
{
	data->player1 = ft_create_bag_of_colors(data, "b", "c");
	if (!data->player1)
		return (-1);
	data->player2 = ft_create_bag_of_colors(data, "d", "e");
	if (!data->player2)
		return (-1);
	return (0);
}

t_player	*ft_create_bag_of_colors(t_vari *data, char *color1, char *color2)
{
	t_player	*player;
	int i;

	player = malloc(sizeof(t_player));
	// tile_set contains max_colors, equal distribution of 2 colors.
	for (i = 0; i < (data->max_colors / 2); i++)
	{
		if (i == 0)
			player->tile_set = ft_strdup(color1);
		else
			player->tile_set = ft_strjoin(player->tile_set, color1);
	}
	for (i = 0; i < (data->max_colors / 2); i++)
		player->tile_set = ft_strjoin(player->tile_set, color2);
	return (player);
}

void	ft_update_bag(t_vari *data, char color)
{
	if(data->currentplayer == 1)
	{
		if(color == data->player1->tile1)
			data->player1->tile_set = ft_charjoin(data->player1->tile_set, data->player1->tile2);
		else
			data->player1->tile_set = ft_charjoin(data->player1->tile_set, data->player1->tile1);
	}
	if(data->currentplayer == 2)
	{
		if(color == data->player2->tile1)
			data->player2->tile_set = ft_charjoin(data->player2->tile_set, data->player2->tile2);
		else
			data->player2->tile_set = ft_charjoin(data->player2->tile_set, data->player2->tile1);
	}
}
