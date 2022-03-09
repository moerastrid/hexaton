#include "../include/hexathon.h"

void    gravity(char **grid, int xpos)
{
    int     i;
    char    c;
    i = 0;
    while ((grid[xpos][i] != 'a') && (grid[xpos][i + 1] == 'a'))
    {
        c = grid[xpos][i];
        grid[xpos][i] = 'a';
        grid[xpos][i + 1] = c;
        i += 1;
    }
}
