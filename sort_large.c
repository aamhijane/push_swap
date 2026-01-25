/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:30:58 by ayamhija          #+#    #+#             */
/*   Updated: 2026/01/26 00:33:30 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_target_in_a(t_stack *a, int b_value)
{
	int	i;
	int	best_idx;
	int	best_val;

	i = 0;
	best_idx = -1;
	best_val = INT_MAX;
	while (i < a->size)
	{
		if (a->array[i] > b_value && a->array[i] < best_val)
		{
			best_val = a->array[i];
			best_idx = i;
		}
		i++;
	}
	if (best_idx == -1)
		best_idx = find_min_index(a);
	return (best_idx);
}

int	calc_moves_a(int target_idx, int size_a)
{
	int	moves_ra;
	int	moves_rra;

	moves_ra = size_a - 1 - target_idx;
	moves_rra = target_idx + 1;
	if (moves_ra < moves_rra)
		return (moves_ra);
	else
		return (-moves_rra);
}

int	calc_moves_b(int b_idx, int size_b)
{
	int	moves_rb;
	int	moves_rrb;

	moves_rb = size_b - 1 - b_idx;
	moves_rrb = b_idx + 1;
	if (moves_rb < moves_rrb)
		return (moves_rb);
	else
		return (-moves_rrb);
}

int	calc_total_cost(int cost_a, int cost_b)
{
	int	total;

	if ((cost_a >= 0 && cost_b >= 0) || (cost_a < 0 && cost_b < 0))
	{
		if (abs_val(cost_a) > abs_val(cost_b))
			total = abs_val(cost_a);
		else
			total = abs_val(cost_b);
	}
	else
		total = abs_val(cost_a) + abs_val(cost_b);
	return (total);
}

void	find_cheapest(t_stack *a, t_stack *b, int *cost_a, int *cost_b)
{
	int	i;
	int	target_idx;
	int	tmp_cost_a;
	int	tmp_cost_b;
	int	min_cost;

	i = 0;
	min_cost = INT_MAX;
	while (i < b->size)
	{
		target_idx = find_target_in_a(a, b->array[i]);
		tmp_cost_a = calc_moves_a(target_idx, a->size);
		tmp_cost_b = calc_moves_b(i, b->size);
		if (calc_total_cost(tmp_cost_a, tmp_cost_b) < min_cost)
		{
			min_cost = calc_total_cost(tmp_cost_a, tmp_cost_b);
			*cost_a = tmp_cost_a;
			*cost_b = tmp_cost_b;
		}
		i++;
	}
}
