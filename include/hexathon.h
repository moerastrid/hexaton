/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hexathon.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 00:07:22 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/11 00:36:09 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEXATHON_H
# define HEXATHON_H
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <string.h>
# include <time.h>
# include <sys/types.h>
# include <stdio.h>
# include <assert.h>
# include "MLX42/MLX42.h"

# define WIDTH 1200
# define HEIGHT 1200
# define SIDE 5
# define INROW 4
# define WAITTIME 1
# define EMPTYBAG "No more tiles, you lose\n"
# define BAGERROR "Creating the bag of colors failed for some reason\n"

typedef struct s_player
{
	char	*tile_set;
	char	tile1;
	char	tile2;
}	t_player;

typedef struct s_player_bot
{
    pid_t pid;
    int stdin[2];
    int stdout[2];
    FILE* reader;
} player_bot_t;

typedef struct s_vari
{
	int		size;
	int		colors;
	int		shape;
	int		figure;
	char	**grid;
	int		max_tiles;
	int		max_colors;
	int		currentplayer;
	t_player	*player1;
	t_player	*player2;
	mlx_t		*mlx;
	mlx_image_t	*img;
}		t_vari;

typedef struct s_loopdata
{
	t_vari *data;
	mlx_texture_t **hexagons;
	player_bot_t *player_bot1;
	player_bot_t *player_bot2;
}		t_loopdata;


//bag_of_colors
char	*ft_charjoin(char *s1, char s2);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
int 	ft_picking_tiles(t_vari *data, int current_player);
int		ft_create_bags_of_colors(t_vari *data);
t_player	*ft_create_bag_of_colors(t_vari *data, char *color1, char *color2);
void	ft_update_bag(t_vari *data, char color);
//convertinput
void    ft_convert_input(t_vari *data, char *input);
//draw
void	ft_draw_hexagon(int32_t x, int32_t y, mlx_image_t *img, char c, mlx_texture_t *hexagons[]);
void	ft_draw(t_vari *data,mlx_texture_t *hexagons[]);
//fill
void    ft_fill(t_vari *data);
//gravity
void    gravity(t_vari *data, int xpos);
void	full_one_eighty(char **grid, int size);
//grid
char	**ft_grid(int side);
//init_player_bot
int init_player(const char* path, player_bot_t* player);
//itoa
char	*ft_itoa(int n);
//keypress
mlx_keyfunc	ft_keypress(mlx_key_data_t keydata, void *invar);
//turn
int		ft_turn();
//gameloop
void	gameloop(void *invar);
//makeoutput
char	*ft_makeoutput(t_vari *data);
//win
bool ft_checkbelow(int j, int i, t_vari *data, char currentc, int counter);
bool ft_checktoside(int j, int i, t_vari *data, char currentc, int counter);
bool ft_checkotherside(int j, int i, t_vari *data, char currentc, int counter);
bool    ft_wincheck(t_vari	*data);
bool    ft_win(t_vari	*data);
//wrap
uint32_t ft_getpixel(uint8_t* pixel);
bool my_mlx_draw_texture(mlx_image_t* image, mlx_texture_t* texture, int32_t x, int32_t y);
void	ft_pixelputwrap(mlx_image_t *img, int x, int y, unsigned int color);
void	mlx_draw_texture_wrap(mlx_image_t *img, mlx_texture_t *texture, int32_t x, int32_t y);
//free_stuff
void		ft_free_at_last(t_vari *data);

#endif
