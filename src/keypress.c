/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keypress.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 19:24:36 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/09 17:03:31 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/hexathon.h"

mlx_keyfunc	ft_keypress(mlx_key_data_t keydata, void *invar)
{
	t_vari	*data;
	char	**tempgrid;
	
	data = (t_vari *)invar;
	tempgrid = malloc(1000);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
    {
		mlx_close_window(data->mlx);
    }
    if (keydata.key == MLX_KEY_A
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{
		printf("left\n");
	}
	if (keydata.key == MLX_KEY_D
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{
		printf("right\n");
	}
	if (keydata.key == MLX_KEY_S
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{
		printf("down\n");
	}
	if (keydata.key == MLX_KEY_W
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{
		printf("up\n");
	}
	free(tempgrid);
}
