#include "../include/hexathon.h"

void    ft_convert_input(t_vari *data)
{
    char    input[] = "bllls";
	if (!input)
	{
		printf("no input");
	}

    char    color;
    int     xpos;
    int     rotation;

    rotation = 0;    
    xpos = data->size - 1;

    for(int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == 'a' && (input[i+1] == 'l' || input[i+1] == 'r' || input[i+1] == 's'))
        {
            rotation = 1;
        }
        else if (input[i] == 'b' && (input[i+1] == 'l' || input[i+1] == 'r' || input[i+1] == 's'))
        {
            color = 'b';
            //ft_update_bag();
        }
        else if (input[i] == 'c' && (input[i+1] == 'l' || input[i+1] == 'r' || input[i+1] == 's'))
        {
            color = 'c';
            //ft_update_bag();
        }
        else if (input[i] == 'd' && (input[i+1] == 'l' || input[i+1] == 'r' || input[i+1] == 's'))
        {
            color = 'd';
            //ft_update_bag();
        }
        else if (input[i] == 'e' && (input[i+1] == 'l' || input[i+1] == 'r' || input[i+1] == 's'))
        {
            color = 'e';
            //ft_update_bag();
        }
        else if (input[i] == 'l')
        {
            if (rotation == 0)
            {
                xpos -= 1;
            }
            else
                ft_rotate_left();
        }
        else if (input[i] == 'r')
        {
            if (rotation == 0)
                xpos += 1;
            else
            {
                ft_rotate_right();
            }
        }
        else if (input[i] == 's' && input[i+1] == '\0')
        {
            data->grid[xpos][0] = color;
            gravity(data->grid, xpos);
            return ;
        }
        else
        {
            mlx_close_window(data->mlx);
            printf("invalid input");
        }
    }
    return ;
}
