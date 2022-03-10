/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bag_of_colors.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 10:45:38 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/03/10 13:53:11 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include "../include/hexathon.h"

char	*ft_charjoin(char const *s1, char s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	newstr = calloc(sizeof(char), strlen(s1) + 2);
	if (!newstr)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		newstr[j] = s1[i];
		i++;
		j++;
	}
	newstr[j] = s2;
	free(s1);
	return (newstr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	newstr = calloc(sizeof(char), strlen(s1) + strlen(s2) + 1);
	if (!newstr)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		newstr[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		newstr[j] = s2[i];
		i++;
		j++;
	}
	free(s1);
	return (newstr);
}

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

int 	ft_picking_tiles(t_vari *data, int current_player)
{
	if (current_player == 1)
	{
		int upper = strlen(data->player1->tile_set);
		int lower = 0;

		// size_t len = strlen(data->player1->tile_set);
		if (upper == 0) /* We are all out of characters */
			return (printf("Game over!\n"));
		/* Select a character at random */
		int rv = (arc4random() % (upper - lower + 1)) + lower;
		data->player1->tile1 = data->player1->tile_set[rv];
		/* Remove the selected character from the set */ 
		data->player1->tile_set[rv] = data->player1->tile_set[upper - 1];
		data->player1->tile_set[upper - 1] = '\0';
		upper = strlen(data->player1->tile_set); //reducing upper limit for using arc4random
		if (upper == 0) /* We are all out of characters */
			return (printf("Game over!\n"));
		/* Select a character at random */
		rv = (arc4random() % (upper - lower + 1)) + lower;
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
			return (printf("Game over!\n"));
		/* Select a character at random */
		int rv = (arc4random() % (upper - lower + 1)) + lower;
		data->player2->tile1 = data->player2->tile_set[rv];
		/* Remove the selected character from the set */ 
		data->player2->tile_set[rv] = data->player2->tile_set[upper - 1];
		data->player2->tile_set[upper - 1] = '\0';
		upper = strlen(data->player2->tile_set); //updating upper limit for using arc4random
		if (upper == 0) /* We are all out of characters */
			return (printf("Game over!\n"));
		/* Select a character at random */
		rv = (arc4random() % (upper - lower + 1)) + lower;
		data->player2->tile2 = data->player2->tile_set[rv];
		/* Remove the selected character from the set */ 
		data->player2->tile_set[rv] = data->player2->tile_set[upper - 1];
		data->player2->tile_set[upper - 1] = '\0';
		return(0);
	}
	else
	{
		printf("ERROR!!!\n");
		return(0);
	}
}

void	ft_create_bags_of_colors(t_vari *data)
{
	data->player1 = ft_create_bag_of_colors(data, "b", "c");
	data->player2 = ft_create_bag_of_colors(data, "d", "e");
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
