#include "../include/hexathon.h"

void    ft_convert(char *input)
{
    for(int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == 'a')
        {
            ft_rotate();
        }
        else if (input[i] == 'b')
        {
            
        }
        else if (input[i] == 'c')
        {
        
        }
        else if (input[i] == 'd')
        {
        
        }
        else if (input[i] == 'e')
        {
        
        }
        else if (input[i] == 'l')
        {
            ft_move_left();
        }
        else if (input[i] == 'r')
        {
            ft_move_right();
        }
        else if (input[i] == 's')
        {
        
        }
        else 
            printf("invalid input");
    }
}
