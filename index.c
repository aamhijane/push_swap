/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 00:16:18 by ayamhija          #+#    #+#             */
/*   Updated: 2026/01/23 00:16:30 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	copy_array(int *src, int *dst, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
}

static void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;
	int	min_idx;

	i = 0;
	while (i < size)
	{
		min_idx = i;
		j = i + 1;
		while (j < size)
		{
			if (arr[j] < arr[min_idx])
				min_idx = j;
			j++;
		}
		temp = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = temp;
		i++;
	}
}

static int	find_rank(int *sorted, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	index_stack(t_stack *stack)
{
	int	i;
	int	*sorted;
	int	*ranks;

	sorted = (int *)malloc(sizeof(int) * stack->size);
	ranks = (int *)malloc(sizeof(int) * stack->size);
	if (!sorted || !ranks)
		return ;
	copy_array(stack->array, sorted, stack->size);
	sort_array(sorted, stack->size);
	i = 0;
	while (i < stack->size)
	{
		ranks[i] = find_rank(sorted, stack->size, stack->array[i]);
		i++;
	}
	copy_array(ranks, stack->array, stack->size);
	free(sorted);
	free(ranks);
}
