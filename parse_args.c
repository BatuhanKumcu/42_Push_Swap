/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakumcu <bakumcu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:12:40 by bakumcu           #+#    #+#             */
/*   Updated: 2026/04/29 17:12:41 by bakumcu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_parse_init(t_parse *parse)
{
	parse->values = NULL;
	parse->size = 0;
	parse->cap = 0;
	parse->strategy = STRAT_ADAPTIVE;
	parse->has_strategy = 0;
	parse->bench = 0;
}

void	ps_parse_clear(t_parse *parse)
{
	ps_free_ints(&parse->values);
	parse->size = 0;
	parse->cap = 0;
}

static int	ps_parse_word(t_parse *parse, char *str, int *pos)
{
	int	start;
	int	end;
	int	value;

	start = *pos;
	while (str[*pos] && !ps_is_space(str[*pos]))
		(*pos)++;
	end = *pos;
	if (str[start] == '-' && str[start + 1] == '-')
		return (ps_parse_flag(parse, str, start, end));
	if (!ps_parse_int(str, start, end, &value))
		return (0);
	return (ps_parse_push(parse, value));
}

static int	ps_parse_arg(t_parse *parse, char *str)
{
	int	pos;
	int	has_word;

	pos = 0;
	has_word = 0;
	while (str[pos])
	{
		while (str[pos] && ps_is_space(str[pos]))
			pos++;
		if (str[pos])
		{
			has_word = 1;
			if (!ps_parse_word(parse, str, &pos))
				return (0);
		}
	}
	return (has_word);
}

int	ps_parse_args(int argc, char **argv, t_parse *parse)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ps_parse_arg(parse, argv[i]))
			return (0);
		i++;
	}
	if (parse->size == 0)
		return (0);
	if (ps_has_duplicate(parse->values, parse->size))
		return (0);
	return (1);
}
