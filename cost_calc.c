/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 00:17:45 by ayamhija          #+#    #+#             */
/*   Updated: 2026/01/23 00:17:52 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_smallest_bigger(t_stack *a, int value)
{
	int	target_pos;
	int	target_val;
	int	i;

	target_pos = 0;
	target_val = INT_MAX;
	i = 0;
	while (i < a->size)
	{
		if (a->array[i] > value && a->array[i] < target_val)
		{
			target_pos = i;
			target_val = a->array[i];
		}
		i++;
	}
	return (target_pos);
}

int	find_target_pos(t_stack *a, int value)
{
	int	target_pos;
	int	min;

	target_pos = find_smallest_bigger(a, value);
	if (target_pos == 0 && a->array[0] <= value)
	{
		min = find_min(a);
		target_pos = find_position(a, min);
	}
	return (target_pos);
}

static void	set_rotation_costs(t_cost *cost, t_stack *a,
				t_stack *b, int pos_b)
{
	int	target_pos;

	target_pos = find_target_pos(a, b->array[pos_b]);
	if (pos_b <= b->size / 2)
		cost->cost_b = pos_b;
	else
		cost->cost_b = -(b->size - pos_b);
	if (target_pos <= a->size / 2)
		cost->cost_a = target_pos;
	else
		cost->cost_a = -(a->size - target_pos);
}

t_cost	calculate_cost(t_stack *a, t_stack *b, int pos_b)
{
	t_cost	cost;

	set_rotation_costs(&cost, a, b, pos_b);
	cost.use_rr = 0;
	cost.use_rrr = 0;
	if (cost.cost_a > 0 && cost.cost_b > 0)
	{
		cost.use_rr = 1;
		if (cost.cost_a > cost.cost_b)
			cost.total = cost.cost_a;
		else
			cost.total = cost.cost_b;
	}
	return (cost);
}
