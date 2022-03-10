/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_stuff.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 14:09:14 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/03/10 15:49:19 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/hexathon.h"

static char	**ft_free_array(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}

void	ft_free_at_last(t_vari *data)
{
	data->grid = ft_free_array(data->grid);
	free(data->player1->tile_set);
	free(data->player2->tile_set);
	free(data->player1);
	free(data->player2);
}

char	*ft_charjoin(char const *s1, char s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	newstr = calloc(sizeof(char), strlen(s1) + 2);
	if (!newstr)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		newstr[j] = s1[i];
		i++;
		j++;
	}
	newstr[j] = s2;
	free(s1);
	return (newstr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	newstr = calloc(sizeof(char), strlen(s1) + strlen(s2) + 1);
	if (!newstr)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		newstr[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		newstr[j] = s2[i];
		i++;
		j++;
	}
	free(s1);
	return (newstr);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	i;

	dest = malloc(strlen(s) + 1);
	if (!dest)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
