/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakumcu <bakumcu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 11:22:27 by bakumcu           #+#    #+#             */
/*   Updated: 2026/04/29 17:12:49 by bakumcu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_fail_parse(t_parse *parse)
{
	ps_parse_clear(parse);
	ps_error();
	return (1);
}

static int	ps_fail_build(t_parse *parse, t_ctx *ctx)
{
	ps_ctx_clear(ctx);
	ps_parse_clear(parse);
	ps_error();
	return (1);
}

static int	ps_exit_clean(t_parse *parse, t_ctx *ctx)
{
	ps_ctx_clear(ctx);
	ps_parse_clear(parse);
	return (0);
}

int	main(int argc, char **argv)
{
	t_parse	parse;
	t_ctx	ctx;

	if (argc == 1)
		return (0);
	ps_parse_init(&parse);
	ps_ctx_init(&ctx);
	if (!ps_parse_args(argc, argv, &parse))
		return (ps_fail_parse(&parse));
	if (!ps_stack_build(&ctx, &parse))
		return (ps_fail_build(&parse, &ctx));
	if (ps_is_sorted(&ctx.a))
		return (ps_exit_clean(&parse, &ctx));
	ps_algo_simple(&ctx);
	return (ps_exit_clean(&parse, &ctx));
}
