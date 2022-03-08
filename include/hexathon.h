/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hexathon.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 16:38:46 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/07 21:46:51 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEXATHON_H
# define HEXATHON_H
# include <stdlib.h>
# include <unistd.h>
# include "MLX42/MLX42.h"
# include <math.h>

typedef struct s_vari
{
	int		size;
	int		colors;
	int		shape;
	int		figure;
	char	**grid;
}		t_vari;

char	**ft_setup_grid(int total_size);
int		ft_total_size_grid(t_vari *data);
char	**ft_grid(t_vari *data);
void	ft_pixelputwrap(mlx_image_t *img, int x, int y, unsigned int color);

#endif