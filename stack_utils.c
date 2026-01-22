/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 00:08:24 by ayamhija          #+#    #+#             */
/*   Updated: 2026/01/23 00:08:25 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(int capacity)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->array = malloc(sizeof(int) * capacity);
	if (stack->array == NULL)
	{
		free(stack);
		return (NULL);
	}
	stack->size = 0;
	stack->capacity = capacity;
	return (stack);
}

void	free_stack(t_stack *stack)
{
	if (stack)
	{
		if (stack->array)
			free(stack->array);
		free(stack);
	}
}

void	free_and_exit(t_stack *a, t_stack *b, int exit_code)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	if (exit_code == 1)
		print_error();
	exit(exit_code);
}

int	is_empty(t_stack *stack)
{
	return (stack->size == 0);
}

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->array[i] > stack->array[i + 1])
			return (0);
		i++;
	}
	return (1);
}
