/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:29:15 by ayamhija          #+#    #+#             */
/*   Updated: 2026/01/25 18:29:18 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	int	temp;
	int	i;

	if (!stack || stack->size < 2)
		return ;
	temp = stack->array[stack->size - 1];
	i = stack->size - 1;
	while (i > 0)
	{
		stack->array[i] = stack->array[i - 1];
		i--;
	}
	stack->array[0] = temp;
}

void	ra(t_stack *a, bool print)
{
	rotate(a);
	if (print)
		ft_putendl_fd("ra", 1);
}

void	rb(t_stack *b, bool print)
{
	rotate(b);
	if (print)
		ft_putendl_fd("rb", 1);
}

void	rr(t_stack *a, t_stack *b, bool print)
{
	rotate(a);
	rotate(b);
	if (print)
		ft_putendl_fd("rr", 1);
}
