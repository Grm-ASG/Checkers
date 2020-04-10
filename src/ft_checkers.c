#include "header.h"

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

    k = 0;
	if (*res == 0)
	{
			**res = j + 'A';
			(*(*res + 1)) = i + '0';
			(*(*res + 2)) = 0;
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
	if (j <= 1 || i >= 7 || argv[i + 1][j - 1] == 'w' ||
		argv[i + 1][j - 1] == 'W' || argv[i + 1][j - 1] == '.'||
        argv[i + 2][j - 2] != '.')
		return (0);
	return (1);
}

int			 ft_check_left_up_W(char argv[][9], int i, int j)
{
	if (j <= 1 || i >= 7 || argv[i + 1][j - 1] == 'w' ||
		argv[i + 1][j - 1] == 'W' || argv[i + 1][j - 1] == '.'||
        argv[i + 2][j - 2] != '.')
		return (0);
	return (1);
}

int			 ft_check_left_down(char argv[][9], int i, int j)
{
	if (j <= 1 || i <= 2 || argv[i - 1][j - 1] == 'w' ||
		argv[i - 1][j - 1] == 'W' || argv[i - 1][j - 1] == '.' ||
        argv[i - 2][j - 2] != '.')
		return (0);
	return (1);
}

int			 ft_check_right_down(char argv[][9], int i, int j)
{
	if (j >= 6 || i <= 2 || argv[i - 1][j + 1] == 'w' ||
		argv[i - 1][j + 1] == 'W' || argv[i - 1][j + 1] == '.' ||
        argv[i - 2][j + 2] != '.')
		return (0);
	return (1);
}

int			 ft_check_right_up(char **argv, int i, int j)
{
	if (j >= 6 || i >= 7 || argv[i + 1][j + 1] == 'w' ||
		argv[i + 1][j + 1] == 'W' || argv[i + 1][j + 1] == '.' ||
        argv[i + 2][j + 2] != '.')
		return (0);
	return (1);
}

int			 ft_check_right_up_W(char argv[][9], int i, int j)
{
	if (j >= 6 || i >= 7 || argv[i + 1][j + 1] == 'w' ||
		argv[i + 1][j + 1] == 'W' || argv[i + 1][j + 1] == '.' ||
        argv[i + 2][j + 2] != '.')
		return (0);
	return (1);
}

void			ft_check_branch(char **argv, int i, int j, char *tmp, char **res)
{
	char	temp2[256];
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
	temp2[k++] = i + '0';
    temp2[k] = 0;
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

void            ft_check_branch_W(char map[][9], int i, int j, char *tmp, char **res)
{
    char    tmp_map[10][9];
	char	temp2[256];
	int     k;
    int     l;

    tmp_map[0][0] = 0;
    tmp_map[9][0] = 0;
    k = 1;
    while (k < 9)
    {
        l = 0;
        while(l < 8)
        {
            tmp_map[k][l] = map[k][l];
            l++;
        }
        k++;
    }
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
	temp2[k++] = i + '0';
	temp2[k] = 0;
	if (!(ft_check_left_up_W(map, i, j)) && !(ft_check_right_up_W(map, i, j)) && 
        !(ft_check_left_down(map, i, j)) && !(ft_check_right_down(map, i, j)))
	{
		if(ft_strlen(temp2) > ft_strlen(*res))
			ft_res_copy(res, temp2, i, j);
		return ;
	}
    else
    {
        tmp_map[i][j] = '.';
        if (ft_check_left_down(map, i, j))
        {
            tmp_map[i - 1][j - 1] = '.';
            ft_check_branch_W(tmp_map, i - 2, j - 2, temp2, res); 
        }
        if (ft_check_left_up_W(map, i, j))
        {
            tmp_map[i + 1][j - 1] = '.';
            ft_check_branch_W(tmp_map, i + 2, j - 2, temp2, res);
        }
        if (ft_check_right_down(map, i, j))
        {
            tmp_map[i - 1][j + 1] = '.';
            ft_check_branch_W(tmp_map, i - 2, j + 2, temp2, res); 
        }
        if (ft_check_right_up_W(map, i, j))
        {
            tmp_map[i + 1][j + 1] = '.';
            ft_check_branch_W(tmp_map, i + 2, j + 2, temp2, res);
        }
    }
}

void			ft_check_var(char **argv, int i, int j, char **res)
{
	char	tmp[256];
    char    tmp_map[10][9];
	int     k;
    int     l;

    tmp_map[0][0] = 0;
    tmp_map[9][0] = 0;
    k = 1;
	ft_memset(tmp, 0, 256);
    while (k < 9)
    {
        l = 0;
        while(l < 8)
        {
            tmp_map[k][l] = argv[k][l];
            l++;
        }
        k++;
    }
	if (argv[i][j] == 'w')
	   ft_check_branch(argv, i, j, tmp, res);
	else if(argv[i][j] == 'W')
		ft_check_branch_W(tmp_map, i, j, tmp, res);
	if ((*res) == 0)
		ft_res_copy(res, tmp, i, j);
}

void			ft_solve_checkers(char **argv)
{
	char	*res;
	int	 i;
	int	 j;

	i = 1;
	res = (char *)malloc(sizeof(char) * 256);
	res = ft_memset(res, 0, 256);
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == 'w' || argv[i][j] == 'W')
				ft_check_var(argv, i, j, &res);
			j++;
		}
		i++;
	}
	ft_putstr(res);
	ft_putchar('\n');
	free(res);
}

void			ft_checkers(char **argv)
{
	if (ft_check_map(argv))
		ft_putstr(ERR);
	else
	{
		ft_solve_checkers(argv);
	}
}
