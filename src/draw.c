/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 19:37:09 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/08 19:38:20 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/hexathon.h"

void	ft_draw_hexagon(int32_t x, int32_t y, mlx_image_t *img, char c)
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
	int	i;
	int j;

	for (int j = 0; data->grid[j] != NULL; j++)
	{
		for (int i = 0; data->grid[j][i] != '\0'; i++)
		{
			if (j < 5)
				ft_draw_hexagon(300 + (j * 58), 300 + (i * 67) - (35 * j), img, data->grid[j][i]);
			else
				ft_draw_hexagon(300 + (j * 58), 300 + (i * 67) + (35 * (j - 8)), img, data->grid[j][i]);
		}
	}
}



