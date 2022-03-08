/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wrap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 19:30:43 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/07 21:30:40 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/hexathon.h"

void	ft_stop(mlx_t *mlx)
{
	//system("leaks hexathon");
	mlx_terminate(mlx);
}

void	ft_pixelputwrap(mlx_image_t *img, int x, int y, unsigned int color)
{
	if (x < img->width && y < img->height)
		mlx_put_pixel(img, x, y, color);
}
