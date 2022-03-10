/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convertinput.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 00:04:16 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/11 00:34:34 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/hexathon.h"

void    ft_convert_input(t_vari *data, char *input)
{
	if (!input)
		printf("no input");

	char	color;
	int		xpos;
	int		rotation;

	xpos = data->size - 1;

	for(int i = 0; input[i] != '\0'; i++)
	{
		if (input[i] == 'a' && (input[i+1] == '\0'))
			full_one_eighty(data->grid, data->size);
		else if (input[i] == 'b' && (input[i+1] == 'l' || input[i+1] == 'r' || input[i+1] == 's'))
		{
			color = 'b';
			ft_update_bag(data, color);
		}
		else if (input[i] == 'c' && (input[i+1] == 'l' || input[i+1] == 'r' || input[i+1] == 's'))
		{
			color = 'c';
			ft_update_bag(data, color);
		}
		else if (input[i] == 'd' && (input[i+1] == 'l' || input[i+1] == 'r' || input[i+1] == 's'))
		{
			color = 'd';
			ft_update_bag(data, color);
		}
		else if (input[i] == 'e' && (input[i+1] == 'l' || input[i+1] == 'r' || input[i+1] == 's'))
		{
			color = 'e';
			ft_update_bag(data, color);
		}
		else if (input[i] == 'l')
		{
			if(xpos < (2 * data->size) -2 && xpos > 0)
				xpos -= 1;
		}
		else if (input[i] == 'r')
		{
			if(xpos < (2 * data->size) -2 && xpos > 0)
				xpos += 1;
		}
		else if (input[i] == 's' && input[i+1] == '\0')
		{
			if (data->grid[xpos][0] == 'a')
				data->grid[xpos][0] = color;
			else
			{
				printf("invalid input");
				mlx_close_window(data->mlx);
			}
			gravity(data, xpos);
			return ;
		}
		else
		{
			printf("invalid input");
			mlx_close_window(data->mlx);
		}
	}
	return ;
}
