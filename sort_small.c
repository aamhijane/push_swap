/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:30:20 by ayamhija          #+#    #+#             */
/*   Updated: 2026/01/25 18:30:29 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	if (a->size != 3)
		return ;
	top = a->array[2];
	mid = a->array[1];
	bot = a->array[0];
	if (top > mid && mid < bot && top < bot)
		sa(a, true);
	else if (top > mid && mid > bot && top > bot)
	{
		sa(a, true);
		rra(a, true);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(a, true);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a, true);
		ra(a, true);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(a, true);
}

static void	push_min_to_b(t_stack *a, t_stack *b)
{
	int	min_idx;
	int	dist_ra;
	int	dist_rra;

	min_idx = find_min_index(a);
	dist_ra = a->size - 1 - min_idx;
	dist_rra = min_idx + 1;
	if (dist_ra < dist_rra)
	{
		while (dist_ra-- > 0)
			ra(a, true);
	}
	else
	{
		while (dist_rra-- > 0)
			rra(a, true);
	}
	pb(a, b, true);
}

void	sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (a->array[1] > a->array[0])
			sa(a, true);
		return ;
	}
	if (a->size == 3)
	{
		sort_three(a);
		return ;
	}
	while (a->size > 3)
		push_min_to_b(a, b);
	sort_three(a);
	while (b->size > 0)
		pa(a, b, true);
}
