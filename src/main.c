#include "header.h"

int			main(int argc, char **argv)
{
	if (argc != 9)
	{
		ft_putstr(ERR);
	}
	else
	{
		ft_checkers(argv);
	}
	return (0);
}
