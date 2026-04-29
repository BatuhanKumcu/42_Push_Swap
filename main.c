/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakumcu <bakumcu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 11:22:27 by bakumcu           #+#    #+#             */
/*   Updated: 2026/04/29 11:22:28 by bakumcu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_parse	parse;

	if (argc == 1)
		return (0);
	ps_parse_init(&parse);
	if (!ps_parse_args(argc, argv, &parse))
	{
		ps_parse_clear(&parse);
		ps_error();
		return (1);
	}
	ps_parse_clear(&parse);
	return (0);
}
