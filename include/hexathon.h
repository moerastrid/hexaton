/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hexathon.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 16:38:46 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/08 16:02:01 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEXATHON_H
# define HEXATHON_H
# include <stdlib.h>
# include <unistd.h>
# include "MLX42/MLX42.h"
# include <math.h>
# include <string.h>
# include <time.h>

typedef struct s_player
{
	char	tile_set[13];
	char	tile1;
	char	tile2;
}	t_player;

typedef struct s_vari
{
	int		size;
	int		colors;
	int		shape;
	int		figure;
	char	**grid;
	char	max_tiles;
	t_player	player1;
	t_player	player2;
}		t_vari;

char	**ft_setup_grid(int total_size);
int		ft_total_size_grid(t_vari *data);
char	**ft_grid(t_vari *data);
void	ft_pixelputwrap(mlx_image_t *img, int x, int y, unsigned int color);
int		ft_colorbag_player1(t_vari *data);
int		ft_colorbag_player2(t_vari *data);
#endif
