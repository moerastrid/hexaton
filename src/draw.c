/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 19:37:09 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/10 16:50:52 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/hexathon.h"

void	ft_draw_hexagon(int32_t x, int32_t y, mlx_image_t *img, char c, mlx_texture_t *hexagons[])
{
	mlx_texture_t	*texture;

	texture = hexagons[0];
	if (c == 'b')
		texture = hexagons[1];
	else if (c == 'c')
		texture = hexagons[2];
	else if (c == 'd')
		texture = hexagons[3];
	else if (c == 'e')
		texture = hexagons[4];

	mlx_draw_texture_wrap(img, texture, x, y);
}

void	ft_draw(t_vari *data, mlx_texture_t *hexagons[])
{
	ft_fill(data);
	for (int j = 0; data->grid[j] != NULL; j++)
	{
		for (int i = 0; data->grid[j][i] != '\0'; i++)
		{
			if (j < (data->size - 1))
				ft_draw_hexagon(150 + (j * 58), 300 + (i * 67) - (35 * j), data->img, data->grid[j][i], hexagons);
			else
				ft_draw_hexagon(150 + (j * 58), 300 + (i * 67) + (35 * (j - (data->size * 2 - 2))), data->img, data->grid[j][i], hexagons);
		}
	}
	if (data->currentplayer == 1)
	{
		ft_draw_hexagon(10, 50, data->img, data->player1->tile1, hexagons);
		ft_draw_hexagon(75, 50, data->img, data->player1->tile2, hexagons);
	}
	if (data->currentplayer == 2)
	{
		ft_draw_hexagon(10, 50, data->img, data->player2->tile1, hexagons);
		ft_draw_hexagon(75, 50, data->img, data->player2->tile2, hexagons);
	}
}



