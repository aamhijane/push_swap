/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 00:18:04 by ayamhija          #+#    #+#             */
/*   Updated: 2026/01/23 00:18:15 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void	handle_reverse_rotation(t_cost *cost)
{
	int	abs_a;
	int	abs_b;

	cost->use_rrr = 1;
	abs_a = -cost->cost_a;
	abs_b = -cost->cost_b;
	if (abs_a > abs_b)
		cost->total = abs_a;
	else
		cost->total = abs_b;
}

void	finalize_cost(t_cost *cost)
{
	int	abs_a;
	int	abs_b;

	if (cost->cost_a < 0 && cost->cost_b < 0)
	{
		handle_reverse_rotation(cost);
		return ;
	}
	abs_a = get_abs(cost->cost_a);
	abs_b = get_abs(cost->cost_b);
	cost->total = abs_a + abs_b;
}

int	find_cheapest(t_stack *a, t_stack *b)
{
	int		i;
	int		cheapest_pos;
	int		min_cost;
	t_cost	cost;

	min_cost = INT_MAX;
	cheapest_pos = 0;
	i = 0;
	while (i < b->size)
	{
		cost = calculate_cost(a, b, i);
		finalize_cost(&cost);
		if (cost.total < min_cost)
		{
			min_cost = cost.total;
			cheapest_pos = i;
		}
		i++;
	}
	return (cheapest_pos);
}
