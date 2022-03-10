/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   turn.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 00:06:56 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/11 00:06:57 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/hexathon.h"

int	ft_turn()
{
	static int	turncount = 0;
	
	if (turncount % 2 == 0)
	{
		turncount++;
		return (1);
	}
	turncount++;
	return (2);
}
