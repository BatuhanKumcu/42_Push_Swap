/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakumcu <bakumcu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 15:48:38 by bakumcu           #+#    #+#             */
/*   Updated: 2026/05/01 11:22:22 by bakumcu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_simple_sa(t_ctx *ctx)
{
	int	tmp;

	if (ctx->a.size < 2)
		return ;
	tmp = ctx->a.v[0];
	ctx->a.v[0] = ctx->a.v[1];
	ctx->a.v[1] = tmp;
	ps_putstr_fd("sa\n", 1);
}

static void	ps_simple_ra(t_ctx *ctx)
{
	int	tmp;
	int	i;

	if (ctx->a.size < 2)
		return ;
	tmp = ctx->a.v[0];
	i = 0;
	while (i + 1 < ctx->a.size)
	{
		ctx->a.v[i] = ctx->a.v[i + 1];
		i++;
	}
	ctx->a.v[ctx->a.size - 1] = tmp;
	ps_putstr_fd("ra\n", 1);
}

static void	ps_simple_rra(t_ctx *ctx)
{
	int	tmp;
	int	i;

	if (ctx->a.size < 2)
		return ;
	tmp = ctx->a.v[ctx->a.size - 1];
	i = ctx->a.size - 1;
	while (i > 0)
	{
		ctx->a.v[i] = ctx->a.v[i - 1];
		i--;
	}
	ctx->a.v[0] = tmp;
	ps_putstr_fd("rra\n", 1);
}

static void	ps_bubble_swap_at(t_ctx *ctx, int pos)
{
	int	count;

	count = 0;
	if (pos <= ctx->a.size / 2)
	{
		while (count++ < pos)
			ps_simple_ra(ctx);
		ps_simple_sa(ctx);
		while (--count > 0)
			ps_simple_rra(ctx);
	}
	else
	{
		while (count++ < ctx->a.size - pos)
			ps_simple_rra(ctx);
		ps_simple_sa(ctx);
		while (--count > 0)
			ps_simple_ra(ctx);
	}
}

void	ps_algo_simple(t_ctx *ctx)
{
	int	limit;
	int	i;
	int	swapped;

	limit = ctx->a.size;
	while (limit > 1 && !ps_is_sorted(&ctx->a))
	{
		i = 0;
		swapped = 0;
		while (i + 1 < limit)
		{
			if (ctx->a.v[i] > ctx->a.v[i + 1])
			{
				ps_bubble_swap_at(ctx, i);
				swapped = 1;
			}
			i++;
		}
		if (!swapped)
			return ;
		limit--;
	}
}
