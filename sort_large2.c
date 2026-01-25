/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 00:31:56 by ayamhija          #+#    #+#             */
/*   Updated: 2026/01/26 00:32:56 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_rotate_both(t_stack *a, t_stack *b, int *ca, int *cb)
{
	while (*ca > 0 && *cb > 0)
	{
		rr(a, b, true);
		(*ca)--;
		(*cb)--;
	}
	while (*ca < 0 && *cb < 0)
	{
		rrr(a, b, true);
		(*ca)++;
		(*cb)++;
	}
}

static void	do_move(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
	do_rotate_both(a, b, &cost_a, &cost_b);
	while (cost_a > 0)
	{
		ra(a, true);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(a, true);
		cost_a++;
	}
	while (cost_b > 0)
	{
		rb(b, true);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(b, true);
		cost_b++;
	}
	pa(a, b, true);
}

static void	push_all_to_b(t_stack *a, t_stack *b)
{
	int	size;
	int	pushed;

	size = a->size;
	pushed = 0;
	while (a->size > 3 && pushed < size - 3)
	{
		pb(a, b, true);
		pushed++;
	}
}

static void	rotate_to_min(t_stack *a)
{
	int	min_idx;
	int	cost;

	min_idx = find_min_index(a);
	cost = calc_moves_a(min_idx, a->size);
	while (cost > 0)
	{
		ra(a, true);
		cost--;
	}
	while (cost < 0)
	{
		rra(a, true);
		cost++;
	}
}

void	turk_sort(t_stack *a, t_stack *b)
{
	int	cost_a;
	int	cost_b;

	push_all_to_b(a, b);
	sort_three(a);
	while (b->size > 0)
	{
		cost_a = 0;
		cost_b = 0;
		find_cheapest(a, b, &cost_a, &cost_b);
		do_move(a, b, cost_a, cost_b);
	}
	if (!is_sorted(a))
		rotate_to_min(a);
}
