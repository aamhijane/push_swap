/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 00:12:11 by ayamhija          #+#    #+#             */
/*   Updated: 2026/01/23 00:12:24 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *dst, t_stack *src)
{
	int	i;

	if (src->size == 0)
		return ;
	i = dst->size;
	while (i > 0)
	{
		dst->array[i] = dst->array[i - 1];
		i--;
	}
	dst->array[0] = src->array[0];
	dst->size++;
	i = 0;
	while (i < src->size - 1)
	{
		src->array[i] = src->array[i + 1];
		i++;
	}
	src->size--;
}

void	pa(t_stack *a, t_stack *b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	push(b, a);
	write(1, "pb\n", 3);
}
