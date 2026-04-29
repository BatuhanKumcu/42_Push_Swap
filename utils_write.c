/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakumcu <bakumcu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:12:05 by bakumcu           #+#    #+#             */
/*   Updated: 2026/04/29 17:12:06 by bakumcu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_putstr_fd(char *str, int fd)
{
	if (!str)
		return ;
	write(fd, str, ps_strlen(str));
}
