/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hexathon.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 16:38:46 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/09 10:44:50 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEXATHON_H
# define HEXATHON_H
# include <stdlib.h>
# include <unistd.h>
# include "MLX42/MLX42.h"
# include <math.h>
# define WIDTH 1200
# define HEIGHT 1200
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
	mlx_t		*mlx;
	mlx_image_t	*img;
}		t_vari;

char	**ft_setup_grid(void);
int		ft_total_size_grid(t_vari *data);
char	**ft_grid(t_vari *data);
void	ft_pixelputwrap(mlx_image_t *img, int x, int y, unsigned int color);
void	ft_draw(t_vari *data, mlx_image_t *img);
void	ft_draw_hexagon(int32_t x, int32_t y, mlx_image_t *img, char c);
void	ft_create_bag_of_colors(t_vari *data);
void	ft_pick_2_colors(t_vari *data);
mlx_keyfunc	ft_keypress(mlx_key_data_t keydata, void *invar);
#endif
