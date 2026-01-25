/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:29:29 by ayamhija          #+#    #+#             */
/*   Updated: 2026/01/25 18:29:31 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	int	temp;
	int	i;

	if (!stack || stack->size < 2)
		return ;
	temp = stack->array[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->array[i] = stack->array[i + 1];
		i++;
	}
	stack->array[stack->size - 1] = temp;
}

void	rra(t_stack *a, bool print)
{
	reverse_rotate(a);
	if (print)
		ft_putendl_fd("rra", 1);
}

void	rrb(t_stack *b, bool print)
{
	reverse_rotate(b);
	if (print)
		ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack *a, t_stack *b, bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print)
		ft_putendl_fd("rrr", 1);
}
