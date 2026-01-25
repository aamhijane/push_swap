/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:28:37 by ayamhija          #+#    #+#             */
/*   Updated: 2026/01/25 18:28:42 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	temp;

	if (!stack || stack->size < 2)
		return ;
	temp = stack->array[stack->size - 1];
	stack->array[stack->size - 1] = stack->array[stack->size - 2];
	stack->array[stack->size - 2] = temp;
}

void	sa(t_stack *a, bool print)
{
	swap(a);
	if (print)
		ft_putendl_fd("sa", 1);
}

void	sb(t_stack *b, bool print)
{
	swap(b);
	if (print)
		ft_putendl_fd("sb", 1);
}

void	ss(t_stack *a, t_stack *b, bool print)
{
	swap(a);
	swap(b);
	if (print)
		ft_putendl_fd("ss", 1);
}
