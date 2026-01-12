/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 21:24:12 by ayamhija          #+#    #+#             */
/*   Updated: 2026/01/08 21:30:03 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*create_stack(size_t size)
{
	int	*stack;

	stack = (int *)malloc(sizeof(int) * size);
	if (!stack)
		return (NULL);
	return (stack);
}

void	destroy_stack(void *stack)
{
	free(stack);
}

void	destroy_double_stack(void **stack)
{
	int	i;

	if (!stack)
		return ;

	i = 0;
	while (stack[i])
	{
		free(stack[i]);
		i++;
	}
	free(stack);
}
