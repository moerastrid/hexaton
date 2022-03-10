#include "../include/hexathon.h"

char	*ft_convert_map(t_vari *data)
{
	char *temp;
	int tempi;

	//temp = "";
	tempi = 0;
	for (int j = 0; data->grid[j]; j++)
	{
		for (int i = 0; data->grid[j][i]; i++)
		{
			tempi++;
		}
	}

	temp = calloc(tempi + 1, sizeof(char));
	tempi = 0;
	for (int j = 0; data->grid[j]; j++)
	{
		for (int i = 0; data->grid[j][i]; i++)
		{
			temp[tempi] = data->grid[j][i];
			tempi++;
		}
	}
	//printf("\n map size: %d \n", tempi);
	//printf("\n map: %s \n", temp);
	return(temp);
}

char	*ft_makeoutput(t_vari *data)
{
	char *mapstring;
	char *side;
	char *inrow;
	int fd = 1;
	
	side = ft_itoa(SIDE);
	mapstring = ft_strdup(side);
	free(side);
	inrow = ft_itoa(INROW);
	mapstring = ft_strjoin(mapstring, inrow);
	free(inrow);
	if (data->currentplayer == 1)
	{
		mapstring = ft_strjoin(mapstring, data->player1->tile1);
		mapstring = ft_strjoin(mapstring, data->player1->tile2);
	}
	else if (data->currentplayer == 2)
	{
		mapstring = ft_strjoin(mapstring, data->player2->tile1);
		mapstring = ft_strjoin(mapstring, data->player2->tile2);
	}
	mapstring = ft_strjoin(mapstring, ft_convert_map(data));
	return (mapstring);
}
