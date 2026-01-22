/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 00:18:37 by ayamhija          #+#    #+#             */
/*   Updated: 2026/01/23 00:18:47 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_to_pos(t_stack *a, int target_pos)
{
	int	moves;

	if (target_pos <= a->size / 2)
	{
		moves = target_pos;
		while (moves-- > 0)
			ra(a);
	}
	else
	{
		moves = a->size - target_pos;
		while (moves-- > 0)
			rra(a);
	}
}

void	rotate_b_to_pos(t_stack *b, int target_pos)
{
	int	moves;

	if (target_pos <= b->size / 2)
	{
		moves = target_pos;
		while (moves-- > 0)
			rb(b);
	}
	else
	{
		moves = b->size - target_pos;
		while (moves-- > 0)
			rrb(b);
	}
}

static void	do_rr_rotations(t_stack *a, t_stack *b, t_cost *cost)
{
	int	min_rot;
	int	remaining;

	if (cost->cost_a < cost->cost_b)
		min_rot = cost->cost_a;
	else
		min_rot = cost->cost_b;
	while (min_rot-- > 0)
		rr(a, b);
	remaining = cost->cost_a - cost->cost_b;
	while (remaining > 0 && remaining--)
		ra(a);
	remaining = cost->cost_b - cost->cost_a;
	while (remaining > 0 && remaining--)
		rb(b);
}

static void	do_rrr_rotations(t_stack *a, t_stack *b, t_cost *cost)
{
	int	min_rot;
	int	remaining;

	if (-cost->cost_a < -cost->cost_b)
		min_rot = -cost->cost_a;
	else
		min_rot = -cost->cost_b;
	while (min_rot-- > 0)
		rrr(a, b);
	remaining = -cost->cost_a + cost->cost_b;
	while (remaining > 0 && remaining--)
		rra(a);
	remaining = -cost->cost_b + cost->cost_a;
	while (remaining > 0 && remaining--)
		rrb(b);
}

void	execute_move(t_stack *a, t_stack *b, int pos_b)
{
	int		target_pos;
	t_cost	cost;

	cost = calculate_cost(a, b, pos_b);
	finalize_cost(&cost);
	if (cost.use_rr)
		do_rr_rotations(a, b, &cost);
	else if (cost.use_rrr)
		do_rrr_rotations(a, b, &cost);
	else
	{
		target_pos = find_target_pos(a, b->array[pos_b]);
		rotate_a_to_pos(a, target_pos);
		rotate_b_to_pos(b, pos_b);
	}
	pa(a, b);
}
