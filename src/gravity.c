/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gravity.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bde-meij <bde-meij @student.codam.nl>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 00:05:49 by bde-meij      #+#    #+#                 */
/*   Updated: 2022/03/11 00:25:47 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/hexathon.h"

void    gravity(t_vari *data, int xpos)
{
    int     i;
    char    c;
    i = 0;
    while ((data->grid[xpos][i] != 'a') && (data->grid[xpos][i + 1] == 'a'))
    {
        c = data->grid[xpos][i];
        data->grid[xpos][i] = 'a';
        data->grid[xpos][i + 1] = c;
        i += 1;
    }
}
