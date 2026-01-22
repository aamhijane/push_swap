/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 00:17:16 by ayamhija          #+#    #+#             */
/*   Updated: 2026/01/23 00:17:29 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_rotation(t_stack *a)
{
	int	min_val;
	int	min_pos;

	min_val = find_min(a);
	min_pos = find_position(a, min_val);
	if (min_pos <= a->size / 2)
	{
		while (a->array[0] != min_val)
			ra(a);
	}
	else
	{
		while (a->array[0] != min_val)
			rra(a);
	}
}

void	sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sa(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
	{
		pb(a, b);
		sort_three(a);
		pa(a, b);
		final_rotation(a);
	}
	else if (a->size == 5)
	{
		pb(a, b);
		pb(a, b);
		sort_three(a);
		pa(a, b);
		pa(a, b);
		final_rotation(a);
	}
}

void	turk_sort(t_stack *a, t_stack *b)
{
	int	cheapest;

	while (a->size > 3)
		pb(a, b);
	sort_three(a);
	while (!is_empty(b))
	{
		cheapest = find_cheapest(a, b);
		execute_move(a, b, cheapest);
	}
	final_rotation(a);
}
