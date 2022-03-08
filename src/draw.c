/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 19:37:09 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/08 19:03:19 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/hexathon.h"

void	ft_draw_hexagon(int32_t x, int32_t y, mlx_image_t *img, char c)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("include/hexa.png");
	if (c == 'a')
		texture = mlx_load_png("include/hexa.png");
	else if (c == 'b')
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

void	ft_draw(t_vari data, mlx_image_t *img)
{
	int	i;
	int j;
	
	ft_draw_hexagon(200, 200, img, "include/hexa.png");
	ft_draw_hexagon(264, 200, img, "include/hexb.png");
	ft_draw_hexagon(232, 255, img, "include/hexc.png");
	ft_draw_hexagon(232 - 64, 255, img, "include/hexd.png");
	ft_draw_hexagon(232 + 64, 255, img, "include/hexe.png");
	
	for (int j = 0; data.grid[j] != NULL; j++)
	{
		for (int i = 0; data.grid[j][i] != '\0'; i++)
		{
			if (j < 5)
				ft_draw_hexagon(400 + (j * 58), 300 + (i * 67) - (35 * j), img, data.grid[j][i]);
			else
				ft_draw_hexagon(400 + (j * 58), 300 + (i * 67) + (35 * (j - 8)), img, data.grid[j][i]);
		}
	}
	// j = 0;
	// while (*data.grid[j] != NULL)
	// {
	// 	i = 0;
	// 	while (data.grid[j][i] != NULL)
	// 	{
	// 		ft_draw_hexagon(300 + (i * 64) - (j * 32), 400 + (j * 55), img, "include/hexa.png");
	// 		i++;
	// 	}
	// 	j++;
	// }
}



