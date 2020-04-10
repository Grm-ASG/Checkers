#include "header.h"

void			*ft_memset(void *memptr, int val, size_t num)
{
	char *back_up;

	back_up = memptr;
	while (num--)
		*back_up++ = val;
	return (memptr);
}
