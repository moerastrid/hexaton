/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bag_of_colors.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 10:45:38 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/03/09 11:35:08 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include "../include/hexathon.h"

char	random_tile_grabber1(t_vari *data)
{
	char ret;
	int upper = 12;
	int lower = 0;

	size_t len = strlen(data->player1.tile_set);
	if (len == 0) /* We are all out of characters */
		return (-1);
	/* Select a character at random */
	int rv = (arc4random() % (upper - lower + 1)) + lower;
	ret = data->player1.tile_set[rv];
	/* Remove the selected character from the set */ 
	data->player1.tile_set[rv] = data->player1.tile_set[len - 1];
	data->player1.tile_set[len - 1] = '\0';
	upper--; //reducing upper limit for using arc4random
	/* Return the character */
	return (ret);
}

char	random_tile_grabber2(t_vari *data)
{
	char ret;
	int upper = 12;
	int lower = 0;

	size_t len = strlen(data->player2.tile_set);
	if (len == 0) /* We are all out of characters */
		return (-1);
	/* Select a character at random */
	int rv = (arc4random() % (upper - lower + 1)) + lower;
	printf("Random (?) number: %i\n", rv);
	ret = data->player2.tile_set[rv];
	/* Remove the selected character from the set */ 
	data->player2.tile_set[rv] = data->player2.tile_set[len - 1];
	data->player2.tile_set[len - 1] = '\0';
	upper--; //reducing upper limit for using arc4random
	/* Return the character */
	return (ret);
}

void	ft_create_bag_of_colors(t_vari *data)
{
	t_player	player1;
	t_player	player2;

	strcpy(player1.tile_set, "ppppppbbbbbb"); //p = purple b = blue
	strcpy(player2.tile_set, "rrrrrroooooo"); //r = red o = orange
	data->player1 = player1;
	data->player2 = player2;
}

