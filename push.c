/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:28:55 by ayamhija          #+#    #+#             */
/*   Updated: 2026/01/25 18:29:02 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *src, t_stack *dst)
{
	if (!src || src->size == 0)
		return ;
	dst->array[dst->size] = src->array[src->size - 1];
	dst->size++;
	src->size--;
}

void	pa(t_stack *a, t_stack *b, bool print)
{
	push(b, a);
	if (print)
		ft_putendl_fd("pa", 1);
}

void	pb(t_stack *a, t_stack *b, bool print)
{
	push(a, b);
	if (print)
		ft_putendl_fd("pb", 1);
}
