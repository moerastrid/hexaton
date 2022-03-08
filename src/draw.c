/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 19:37:09 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/08 17:02:09 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/hexathon.h"

void	ft_draw_hexagon(int32_t x, int32_t y, mlx_image_t *img, const char *path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	mlx_draw_texture_wrap(img, texture, x, y);
	mlx_delete_texture(texture);
}

void	ft_draw(t_vari data, mlx_image_t *img)
{
	int	i;
	int j;
	
	ft_draw_hexagon(200, 200, img, "include/hexa.png");
	ft_draw_hexagon(264, 200, img, "include/hexb.png");
	ft_draw_hexagon(232, 254, img, "include/hexc.png");
}



