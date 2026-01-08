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

void	init_stack(int *stack, size_t stack_size)
{
	stack = malloc(sizeof(int) * stack_size);
}

void	free_stack(int *stack)
{
	free(stack);
}


