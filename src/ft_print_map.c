#include "header.h"

#include <stdio.h>

void            ft_print_blank(int x)
{
    while (x--)
        ft_putchar(' ');
}

void            ft_print_map(char **map)
{
    char    let[]="ABCDEFGH";
    int     i;
    int     j;

    i = 8;
    while (i)
    {
        j = 0;
        while (map[i][j])
        {
            if (j == 0)
            {
                ft_putchar(i + '0');
                ft_print_blank(1);
                ft_putchar('|');

            }
            ft_putchar(map[i][j]);
            if (map[i][j+1] != '\0')
                ft_putchar(' ');
            j++;
        }
        ft_putchar('\n');
        i--;
    }
    i = 0;
    while (i < 18)
    {
        if (i < 3)
            ft_putchar(' ');
        else
            ft_putstr("¯");
        i++;
    }
    ft_putchar('\n');
    i = 0;
    while (let[i])
    {
        if (i == 0)
            ft_print_blank(3);
        ft_putchar(let[i]);
        if (let[i + 1] != '\0')
            ft_putchar(' ');
        i++;
    }
    ft_putchar('\n');
}
