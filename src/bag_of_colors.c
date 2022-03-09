/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bag_of_colors.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 10:45:38 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/03/09 13:32:07 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include "../include/hexathon.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	i;

	dest = malloc(strlen(s) + 1);
	if (!dest)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int 	ft_choose_color(t_vari *data, int current_player)
{
	if (current_player == 1)
	{
		int upper = 12;
		int lower = 0;

		size_t len = strlen(data->player1->tile_set);
		if (len == 0) /* We are all out of characters */
			return (-1);
		/* Select a character at random */
		int rv = (arc4random() % (upper - lower + 1)) + lower;
		data->player1->tile1 = data->player1->tile_set[rv];
		/* Remove the selected character from the set */ 
		data->player1->tile_set[rv] = data->player1->tile_set[len - 1];
		data->player1->tile_set[len - 1] = '\0';
		upper--; //reducing upper limit for using arc4random
		len = strlen(data->player1->tile_set);
		if (len == 0) /* We are all out of characters */
			return (-1);
		/* Select a character at random */
		rv = (arc4random() % (upper - lower + 1)) + lower;
		data->player1->tile2 = data->player1->tile_set[rv];
		/* Remove the selected character from the set */ 
		data->player1->tile_set[rv] = data->player1->tile_set[len - 1];
		data->player1->tile_set[len - 1] = '\0';
		upper--; //reducing upper limit for using arc4random
		return(0);
	}
	if (current_player == 2)
	{
	
		int upper = 12;
		int lower = 0;

		size_t len = strlen(data->player2->tile_set);
		if (len == 0) /* We are all out of characters */
			return (-1);
		/* Select a character at random */
		int rv = (arc4random() % (upper - lower + 1)) + lower;
		data->player2->tile1 = data->player2->tile_set[rv];
		/* Remove the selected character from the set */ 
		data->player2->tile_set[rv] = data->player2->tile_set[len - 1];
		data->player2->tile_set[len - 1] = '\0';
		upper--; //reducing upper limit for using arc4random
		len = strlen(data->player2->tile_set);
		if (len == 0) /* We are all out of characters */
			return (-1);
		/* Select a character at random */
		rv = (arc4random() % (upper - lower + 1)) + lower;
		data->player2->tile2 = data->player2->tile_set[rv];
		/* Remove the selected character from the set */ 
		data->player2->tile_set[rv] = data->player2->tile_set[len - 1];
		data->player2->tile_set[len - 1] = '\0';
		upper--; //reducing upper limit for using arc4random
		return(0);
	}
	else
	{
		printf("ERROR!!!\n");
		return(0);
	}
}


void	ft_create_bag_of_colors(t_vari *data)
{
	t_player	*player1;
	t_player	*player2;

	player1 = malloc(sizeof(char) * 1000);
	player2 = malloc(sizeof(char) * 1000);
	
	player1->tile_set = ft_strdup("bbbbbbcccccc"); //p = purple b = blue
	player2->tile_set = ft_strdup("ddddddeeeeee"); //r = red o = orange
	data->player1 = player1;
	data->player2 = player2;
}

