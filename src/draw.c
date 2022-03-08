/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 19:37:09 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/07 22:25:16 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/hexathon.h"


void	ft_draw_hexagon(int32_t x, int32_t y, int32_t radi, uint32_t color, mlx_image_t *img)
{
	double	width;
	int		j;
	int		i;

	width = radi + 2 * ((radi / 2) / sqrt(3));
	j = 0;
	while (j <= width)
	{
		i = 0;
		while (i <= width)
		{
			ft_pixelputwrap(img, x + i, y + j, color);
			i++;
		}
		i = 0;
		//while (i <= (3.14 / 180) * 60)
		//{
		//	ft_pixelputwrap(img, x + i, y + j, 0xFF00FFFF);
		//	i++;
		//}
		j++;
	}
	printf("width  : %1f\n", width);
	ft_pixelputwrap(img, x, y, color);
}

void	ft_draw(t_vari data, mlx_image_t *img)
{
	ft_draw_hexagon(200, 200, 50, 0xFFFFFFFF, img);
	printf("hey");
}



