/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakumcu <bakumcu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:12:27 by bakumcu           #+#    #+#             */
/*   Updated: 2026/04/29 17:12:28 by bakumcu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_read_sign(char *str, int *pos, int end, int *sign)
{
	*sign = 1;
	if (*pos < end && (str[*pos] == '+' || str[*pos] == '-'))
	{
		if (str[*pos] == '-')
			*sign = -1;
		(*pos)++;
	}
	return (*pos < end);
}

static int	ps_read_digits(char *str, int *pos, int end, long *number)
{
	while (*pos < end)
	{
		if (!ps_is_digit(str[*pos]))
			return (0);
		*number = *number * 10 + (str[*pos] - '0');
		(*pos)++;
	}
	return (1);
}

int	ps_parse_int(char *str, int start, int end, int *out)
{
	long	number;
	int		sign;
	int		pos;

	number = 0;
	pos = start;
	if (!ps_read_sign(str, &pos, end, &sign))
		return (0);
	if (!ps_read_digits(str, &pos, end, &number))
		return (0);
	if ((sign == 1 && number > 2147483647)
		|| (sign == -1 && number > 2147483648))
		return (0);
	*out = (int)(number * sign);
	return (1);
}

static int	ps_parse_grow(t_parse *parse)
{
	int	*next;
	int	next_cap;
	int	i;

	if (parse->cap == 0)
		next_cap = 8;
	else
		next_cap = parse->cap * 2;
	next = malloc(sizeof(int) * next_cap);
	if (!next)
		return (0);
	i = 0;
	while (i < parse->size)
	{
		next[i] = parse->values[i];
		i++;
	}
	free(parse->values);
	parse->values = next;
	parse->cap = next_cap;
	return (1);
}

int	ps_parse_push(t_parse *parse, int value)
{
	if (parse->size == parse->cap)
	{
		if (!ps_parse_grow(parse))
			return (0);
	}
	parse->values[parse->size] = value;
	parse->size++;
	return (1);
}
