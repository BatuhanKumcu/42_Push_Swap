/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakumcu <bakumcu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:30:00 by bakumcu           #+#    #+#             */
/*   Updated: 2026/04/29 12:30:00 by bakumcu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_value_rank(int *values, int size, int pos)
{
	int	rank;
	int	i;

	rank = 0;
	i = 0;
	while (i < size)
	{
		if (values[i] < values[pos])
			rank++;
		i++;
	}
	return (rank);
}

int	*ps_rank_values(int *values, int size)
{
	int	*ranks;
	int	i;

	ranks = malloc(sizeof(int) * size);
	if (!ranks)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ranks[i] = ps_value_rank(values, size, i);
		i++;
	}
	return (ranks);
}
