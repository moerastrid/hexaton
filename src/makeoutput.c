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

void	ft_makeoutput(t_vari *data)
{
	char *mapstring;
	char *side;
	char *inrow;
	int fd = 1;
	
	side = ft_itoa(SIDE);
	inrow = ft_itoa(INROW);
	mapstring = ft_convert_map(data);
	//write(fd, "vanaf", 5);
	write(fd, side, strlen(side));
	free(side);
	write(fd, ",", 1);
	write(fd, inrow, strlen(inrow));
	free(inrow);
	write(fd, ",", 1);
	if (data->currentplayer == 1)
	{
		write(fd, &data->player1->tile1, 1);
		write(fd, &data->player1->tile2, 1);
	}
	else if (data->currentplayer == 2)
	{
		write(fd, &data->player2->tile1, 1);
		write(fd, &data->player2->tile2, 1);
	}
	write(fd, ",", 1);
	write(fd, mapstring, strlen(mapstring));
	free(mapstring);
	write(fd, "\n", 1);
}
