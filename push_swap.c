/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:32:25 by ayamhija          #+#    #+#             */
/*   Updated: 2026/01/25 18:32:29 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*init_stack_b(int size)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->array = malloc(sizeof(int) * size);
	if (!stack->array)
	{
		free(stack);
		return (NULL);
	}
	stack->size = 0;
	return (stack);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = parse_args(argc, argv);
	if (!a)
		return (0);
	if (is_sorted(a))
	{
		free_stack(a);
		return (0);
	}
	b = init_stack_b(a->size);
	if (!b)
		error_exit(a, NULL);
	if (a->size <= 5)
		sort_small(a, b);
	else
		turk_sort(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
