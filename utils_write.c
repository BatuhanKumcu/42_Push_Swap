#include "push_swap.h"

void	ps_putstr_fd(char *str, int fd)
{
	if (!str)
		return ;
	write(fd, str, ps_strlen(str));
}
