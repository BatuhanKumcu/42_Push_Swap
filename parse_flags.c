/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakumcu <bakumcu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:30:00 by bakumcu           #+#    #+#             */
/*   Updated: 2026/04/29 12:30:00 by bakumcu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_token_is(char *str, int start, int end, char *word)
{
	int	i;

	i = 0;
	while (word[i] && start + i < end)
	{
		if (str[start + i] != word[i])
			return (0);
		i++;
	}
	return (word[i] == '\0' && start + i == end);
}

static int	ps_set_strategy(t_parse *parse, t_strategy strategy)
{
	if (parse->has_strategy)
		return (0);
	parse->strategy = strategy;
	parse->has_strategy = 1;
	return (1);
}

int	ps_parse_flag(t_parse *parse, char *str, int start, int end)
{
	if (ps_token_is(str, start, end, "--bench"))
	{
		parse->bench = 1;
		return (1);
	}
	if (ps_token_is(str, start, end, "--simple"))
		return (ps_set_strategy(parse, STRAT_SIMPLE));
	if (ps_token_is(str, start, end, "--medium"))
		return (ps_set_strategy(parse, STRAT_MEDIUM));
	if (ps_token_is(str, start, end, "--complex"))
		return (ps_set_strategy(parse, STRAT_COMPLEX));
	if (ps_token_is(str, start, end, "--adaptive"))
		return (ps_set_strategy(parse, STRAT_ADAPTIVE));
	return (0);
}
