#include "header.h"

/*delete*/
#include <stdio.h>

int			 ft_check_map(char **argv)
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
		while (argv[i][j])
		{
			if (((i & 1) == 1 && (j & 1) == 1 && argv[i][j] != '.') ||
				((i & 1) == 0 && (j & 1) == 0 && argv[i][j] != '.'))
				return (1);
			if (argv[i][j] == 'w' || argv[i][j] == 'W' ||
				argv[i][j] == 'b' || argv[i][j] == 'B' ||
				argv[i][j] == '.')
			{
				if (argv[i][j] == 'w' || argv[i][j] == 'W')
					w++;
				else if (argv[i][j] == 'b' || argv[i][j] == 'B')
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
	if (w > 12 || b > 12 || w == 0 || b == 0)
		return (1);
	return (0);
}

void			ft_res_copy(char **res, char *tmp, int i, int j)
{
    int k;

	if (*res == 0)
	{
		if((*res =(char *)malloc(sizeof(char) * 3)))
		{
			**res = j + 'A';
			(*(*res + 1)) = i + '0';
			(*(*res + 2)) = 0;
		}
		else
		{
			ft_putstr("Malloc error\n");
			exit (1);
		}
	}
	else 
    {
        while (tmp[k])
        {
            (*(*res + k)) = tmp[k];
            k++;
        }
    }
}

int			 ft_check_left_up(char **argv, int i, int j)
{
	if (j == 0 || i >= 7 || argv[i + 1][j - 1] == 'w' ||
		argv[i + 1][j - 1] == 'W' || argv[i + 1][j - 1] == '.')
	{
    /*delete*
    *   printf("ft_check_left_up     : current position is argv[%d][%d]\n", i, j);
    */
		return (0);
	}
	return (1);
}

int			 ft_check_right_up(char **argv, int i, int j)
{
	if (j == 7 || i >= 7 || argv[i + 1][j + 1] == 'w' ||
		argv[i + 1][j + 1] == 'W' || argv[i + 1][j + 1] == '.')
	{
    /*delete*
	*   printf("ft_check_right_up    : current position is argv[%d][%d]\n", i, j);
    */
		return (0);
	}
	return (1);
}

void			ft_check_branch(char **argv, int i, int j, char *tmp, char **res)
{
	char    temp2[256];
    int     k;

    ft_memset(temp2, 0, 256);
    k = 0;
    while (tmp[k])
    {
        temp2[k] = tmp[k];
        k++;
    }
    if (k != 0)
        temp2[k++] = '-';
    temp2[k++] = j + 'A';
    temp2[k] = i + '0';
    /*delete
	*   printf("ft_check_branch      : i = %d | j = %d\n", i, j);
    *   printf("RES from i j             = %c%c\n", j + 'A', i + '0');
    *   printf("RES from tmp             = %s\n\n", temp2);
    *   printf("Result                   = %s\n\n", *res);
    */
    if (!(ft_check_left_up(argv, i, j)) && !(ft_check_right_up(argv, i, j)))
    {
        if(ft_strlen(temp2) > ft_strlen(*res))
            ft_res_copy(res, temp2, i, j);
        return ;
    }
    if (ft_check_left_up(argv, i, j))
        ft_check_branch(argv, i + 2, j - 2, temp2, res);
    if (ft_check_right_up(argv, i, j))
	   ft_check_branch(argv, i + 2, j + 2, temp2, res);
}

void			ft_check_var(char **argv, int i, int j, char **res)
{
	char	tmp[256];
    //char    **map;

    ft_memset(tmp, 0, 256);
    /*delete
     *  printf("Res = %s\n", tmp);
     */
	if (argv[i][j] == 'w')
	{
	   ft_check_branch(argv, i, j, tmp, res);
	}
	else if(argv[i][j] == 'W')
	{
      //  map = ft_copy_map(argv);
//        ft_check_branch_W(map);
        // free(map);
	}
    /*delete
     *printf("ft_check_var            : Res = %s\n\n", *res);
     */
	if ((*res) == 0)
		ft_res_copy(res, tmp, i, j);
}

void			ft_solve_checkers(char **argv)
{
	char	*res;
	int     i;
	int     j;

	i = 1;
	res = (char *)malloc(sizeof(char) * 256);
    res = ft_memset(res, 0, 256);
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == 'w' || argv[i][j] == 'W')
			{
				ft_check_var(argv, i, j, &res);
			}
			j++;
		}
		i++;
	}
	ft_putstr(res);
	ft_putchar('\n');
}

void			ft_checkers(char **argv)
{
	if (ft_check_map(argv))
		ft_putstr(ERR);
	else
	{
		ft_solve_checkers(argv);
	//	ft_print_map(argv);
	}
}
