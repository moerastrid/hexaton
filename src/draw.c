/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 19:37:09 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/10 12:43:24 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/hexathon.h"

void	ft_draw_hexagon(int32_t x, int32_t y, mlx_image_t *img, char c, t_vari *data)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("include/hexa.png");
	if (c == 'b')
		texture = mlx_load_png("include/hexb.png");
	else if (c == 'c')
		texture = mlx_load_png("include/hexc.png");
	else if (c == 'd')
		texture = mlx_load_png("include/hexd.png");
	else if (c == 'e')
		texture = mlx_load_png("include/hexe.png");

	mlx_draw_texture_wrap(img, texture, x, y);
	mlx_delete_texture(texture);
}

void	ft_draw(t_vari *data, mlx_image_t *img)
{
	ft_fill(data);
	// data->grid[0][0] = 'b';
	// data->grid[1][0] = 'c';
	// data->grid[0][1] = 'd';
	for (int j = 0; data->grid[j] != NULL; j++)
	{
		for (int i = 0; data->grid[j][i] != '\0'; i++)
		{
			if (j < (data->size -1))
				ft_draw_hexagon(150 + (j * 58), 300 + (i * 67) - (35 * j), img, data->grid[j][i], data);
			else
				ft_draw_hexagon(150 + (j * 58), 300 + (i * 67) + (35 * (j - (data->size * 2 - 2))), img, data->grid[j][i], data);
		}
	}
	if (data->currentplayer == 1)
	{
		ft_draw_hexagon(10, 50, img, data->player1->tile1, data);
		ft_draw_hexagon(75, 50, img, data->player1->tile2, data);
	}
	if (data->currentplayer == 2)
	{
		ft_draw_hexagon(10, 50, img, data->player2->tile1, data);
		ft_draw_hexagon(75, 50, img, data->player2->tile2, data);
	}
}



