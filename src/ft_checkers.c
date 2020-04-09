#include "header.h"

int             ft_check_map(char **map)
{
    int w;
    int b;
    int i;
    int j;

    w = 0;
    b = 0;
    i = 1;
    while (i < 9)
    {
        j = 0;
        while (map[i][j])
        {
            if (((i & 1) == 1 && (j & 1) == 1 && map[i][j] != '.') ||
                ((i & 1) == 0 && (j & 1) == 0 && map[i][j] != '.'))
                return (1);
            if (map[i][j] == 'w' || map[i][j] == 'W' ||
                map[i][j] == 'b' || map[i][j] == 'B' ||
                map[i][j] == '.')
            {
                if (map[i][j] == 'w' || map[i][j] == 'W')
                    w++;
                else if (map[i][j] == 'b' || map[i][j] == 'B')
                    b++;
                j++;
            }
            else
                return (1);
        }
        if (j != 8)
            return (1);
        i++;
    }
    if (w > 12 || b > 12)
        return (1);
    return (0);
}

void            ft_checkers(char **argv)
{
    if (ft_check_map(argv))
        ft_putstr(ERR);
    else
        ft_print_map(argv);
}
