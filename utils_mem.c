#include "push_swap.h"

void	ps_free_ints(int **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
