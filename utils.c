/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:26:07 by ayamhija          #+#    #+#             */
/*   Updated: 2026/01/25 18:26:13 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *stack)
{
	int	i;

	if (!stack || stack->size <= 1)
		return (true);
	i = stack->size - 1;
	while (i > 0)
	{
		if (stack->array[i] > stack->array[i - 1])
			return (false);
		i--;
	}
	return (true);
}

int	find_min_index(t_stack *stack)
{
	int	i;
	int	min_idx;
	int	min_val;

	if (!stack || stack->size == 0)
		return (-1);
	min_idx = 0;
	min_val = stack->array[0];
	i = 1;
	while (i < stack->size)
	{
		if (stack->array[i] < min_val)
		{
			min_val = stack->array[i];
			min_idx = i;
		}
		i++;
	}
	return (min_idx);
}

int	find_max_index(t_stack *stack)
{
	int	i;
	int	max_idx;
	int	max_val;

	if (!stack || stack->size == 0)
		return (-1);
	max_idx = 0;
	max_val = stack->array[0];
	i = 1;
	while (i < stack->size)
	{
		if (stack->array[i] > max_val)
		{
			max_val = stack->array[i];
			max_idx = i;
		}
		i++;
	}
	return (max_idx);
}

int	abs_val(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
