/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wrap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 19:30:43 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/10 23:57:20 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/hexathon.h"

uint32_t ft_getpixel(uint8_t* pixel)
{
	return (*pixel << 24 | *(pixel + 1) << 16 | *(pixel + 2) << 8 | *(pixel + 3));
}

bool my_mlx_draw_texture(mlx_image_t* image, mlx_texture_t* texture, int32_t x, int32_t y)
{
	uint8_t	*pixelx;
	uint8_t	*pixeli;

	if (!texture || !image)
		return (mlx_error(MLX_NULLARG));
	if (x < 0 || y < 0)
		return (mlx_error(MLX_NULLARG));
	if (texture->width > image->width || texture->height > image->height)
		return (mlx_error(MLX_TEXTOBIG));
	for (size_t j = 0; j < texture->height; j++)
	{
		for (size_t i = 0; i < texture->width; i++)
		{
			pixelx = &texture->pixels[(j * texture->width + i) * texture->bytes_per_pixel];
			if (*(pixelx + 3) == 0)
				continue;
			ft_pixelputwrap(image, x + i, y + j, ft_getpixel(pixelx));
		}
	}
	return (true);
}

void	ft_pixelputwrap(mlx_image_t *img, int x, int y, unsigned int color)
{
	if (x < img->width && y < img->height)
		mlx_put_pixel(img, x, y, color);
	else
		printf("error\n");
}

void	mlx_draw_texture_wrap(mlx_image_t *img, mlx_texture_t *texture, int32_t x, int32_t y)
{
	if (x < img->width && (x + texture->width) < img->width && y < img->height && (y + texture->height) < img->height)
		my_mlx_draw_texture(img, texture, x, y);
	else
		printf("error\n");
}
