/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakumcu <bakumcu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:30:00 by bakumcu           #+#    #+#             */
/*   Updated: 2026/04/29 12:30:00 by bakumcu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef enum e_strategy
{
	STRAT_ADAPTIVE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}	t_strategy;

typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_TOTAL
}	t_op;

typedef struct s_stack
{
	int	*v;
	int	size;
	int	cap;
}	t_stack;

typedef struct s_log
{
	int	*ops;
	int	size;
	int	cap;
	int	counts[OP_TOTAL];
}	t_log;

typedef struct s_ctx
{
	t_stack		a;
	t_stack		b;
	t_log		log;
	t_strategy	strategy;
	int			bench;
	double		disorder;
}	t_ctx;

typedef struct s_parse
{
	int			*values;
	int			size;
	int			cap;
	t_strategy	strategy;
	int			has_strategy;
	int			bench;
}	t_parse;

void	ps_error(void);
void	ps_free_ints(int **ptr);
void	ps_putstr_fd(char *str, int fd);
size_t	ps_strlen(char *str);
int		ps_is_digit(char c);
int		ps_is_space(char c);
void	ps_parse_init(t_parse *parse);
void	ps_parse_clear(t_parse *parse);
int		ps_parse_args(int argc, char **argv, t_parse *parse);
int		ps_parse_flag(t_parse *parse, char *str, int start, int end);
int		ps_parse_int(char *str, int start, int end, int *out);
int		ps_parse_push(t_parse *parse, int value);
int		ps_has_duplicate(int *values, int size);
int		*ps_rank_values(int *values, int size);
void	ps_ctx_init(t_ctx *ctx);
void	ps_ctx_clear(t_ctx *ctx);
void	ps_stack_clear(t_stack *stack);
int		ps_stack_build(t_ctx *ctx, t_parse *parse);
int		ps_is_sorted(t_stack *stack);

#endif
