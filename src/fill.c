/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 00:04:28 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/11 00:04:29 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/hexathon.h"

void    ft_fill(t_vari *data)
{
    for (int j = 0; j < data->img->height; j++)
    {
        for (int i = 0; i < data->img->width; i++)
        {
            ft_pixelputwrap(data->img, i, j, 0x87CEEB88);
        }
    }
}