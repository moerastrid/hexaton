/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bag_of_colors.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 10:45:38 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/03/09 17:01:14 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include "../include/hexathon.h"

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
		int upper = 12; // afhankelijk van size maken
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
	
		int upper = 12; // afhankelijk van size maken
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

void	ft_create_bags_of_colors(t_vari *data)
{
	data->player1 = ft_create_bag_of_colors(data, "b", "c");
	data->player2 = ft_create_bag_of_colors(data, "d", "e");
}

// void	ft_create_bag_of_colors(t_vari *data)
// {
// 	t_player	*player1;
// 	t_player	*player2;
// 	int i;

// 	player1 = malloc(sizeof(char) * 1000);
// 	player2 = malloc(sizeof(char) * 1000);

// 	// tile_set contains max_colors, equal distribution of 2 colors.
// 	for (i = 0; i < (data->max_colors / 2); i++)
// 	{
// 		if (i == 0)
// 			player1->tile_set = ft_strdup("b");
// 		else
// 			player1->tile_set = ft_strjoin(player1->tile_set, "b");
// 	}
// 	for (i = 0; i < (data->max_colors / 2); i++)
// 		player1->tile_set = ft_strjoin(player1->tile_set, "c");

// 	for (i = 0; i < (data->max_colors / 2); i++)
// 	{
// 		if (i == 0)
// 			player2->tile_set = ft_strdup("b");
// 		else
// 			player2->tile_set = ft_strjoin(player2->tile_set, "d");
// 	}
// 	for (i = 0; i < (data->max_colors / 2); i++)
// 		player2->tile_set = ft_strjoin(player2->tile_set, "e");
	
// 	// player1->tile_set = ft_strdup("bbbbbbcccccc"); //p = purple b = blue
// 	// player2->tile_set = ft_strdup("ddddddeeeeee"); //r = red o = orange
// 	data->player1 = player1;
// 	data->player2 = player2;
// 	printf("P1 tile set?: %s\n", data->player1->tile_set);
// }

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
