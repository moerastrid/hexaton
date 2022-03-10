/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keypress.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 19:24:36 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/10 23:56:39 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/hexathon.h"

mlx_keyfunc	ft_keypress(mlx_key_data_t keydata, void *invar)
{
	t_vari	*data;
	
	data = (t_vari *)invar;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
    {
		mlx_close_window(data->mlx);
    }
}
