/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakumcu <bakumcu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:30:00 by bakumcu           #+#    #+#             */
/*   Updated: 2026/04/29 12:30:00 by bakumcu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_log_init(t_log *log)
{
	int	i;

	log->ops = NULL;
	log->size = 0;
	log->cap = 0;
	i = 0;
	while (i < OP_TOTAL)
	{
		log->counts[i] = 0;
		i++;
	}
}

void	ps_ctx_init(t_ctx *ctx)
{
	ctx->a.v = NULL;
	ctx->a.size = 0;
	ctx->a.cap = 0;
	ctx->b.v = NULL;
	ctx->b.size = 0;
	ctx->b.cap = 0;
	ps_log_init(&ctx->log);
	ctx->strategy = STRAT_ADAPTIVE;
	ctx->bench = 0;
	ctx->disorder = 0.0;
}

void	ps_stack_clear(t_stack *stack)
{
	ps_free_ints(&stack->v);
	stack->size = 0;
	stack->cap = 0;
}

void	ps_ctx_clear(t_ctx *ctx)
{
	ps_stack_clear(&ctx->a);
	ps_stack_clear(&ctx->b);
	ps_free_ints(&ctx->log.ops);
	ctx->log.size = 0;
	ctx->log.cap = 0;
}

int	ps_stack_build(t_ctx *ctx, t_parse *parse)
{
	ctx->strategy = parse->strategy;
	ctx->bench = parse->bench;
	ctx->a.v = ps_rank_values(parse->values, parse->size);
	if (!ctx->a.v)
		return (0);
	ctx->a.size = parse->size;
	ctx->a.cap = parse->size;
	ctx->b.v = malloc(sizeof(int) * parse->size);
	if (!ctx->b.v)
		return (0);
	ctx->b.size = 0;
	ctx->b.cap = parse->size;
	return (1);
}
