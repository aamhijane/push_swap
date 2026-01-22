/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 00:16:47 by ayamhija          #+#    #+#             */
/*   Updated: 2026/01/23 00:17:02 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_case_1(t_stack *a, int max_pos)
{
	if (max_pos == 0)
		ra(a);
	else if (max_pos == 1)
		rra(a);
}

static void	sort_case_2(t_stack *a, int max_pos)
{
	if (max_pos == 0)
	{
		sa(a);
		rra(a);
	}
	else if (max_pos == 1)
	{
		sa(a);
		ra(a);
	}
	else
		sa(a);
}

void	sort_three(t_stack *a)
{
	int	max_pos;
	int	max;

	if (is_sorted(a))
		return ;
	max = find_max(a);
	max_pos = find_position(a, max);
	if (a->array[0] < a->array[1])
		sort_case_1(a, max_pos);
	else
		sort_case_2(a, max_pos);
}
