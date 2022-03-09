#include "../include/hexathon.h"

void    ft_fill(t_vari *data)
{
    for (int j = 0; j < data->img->height; j++)
    {
        for (int i = 0; i < data->img->width; i++)
        {
            ft_pixelputwrap(data->img, i, j, 0x87CEEB44);
        }
    }
}