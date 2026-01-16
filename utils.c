/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 22:45:06 by ayamhija          #+#    #+#             */
/*   Updated: 2026/01/06 22:45:41 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	stack_size(char **arguments)
{
	int	i;

	i = 0;
	while (arguments[i] != NULL)
		i++;
	return (i);
}

void	fill_stack(int *stack, char **args, size_t size, int *top)
{
	int	i;

	i = 0;
	while (i < size)
	{
		stack[i] = ft_atoi(args[i]);
		(*top)++;
		i++;
	}
}

int	idx_of_large(int *stack, int *top)
{
	int	curr;
	int	idx;
	int	i;

	curr = -2147483648;
	idx = -1;
	i = 0;
	while (i <= *top) {
		if (stack[i] > curr)
		{
			curr = stack[i];
			idx = i;
		}
		i++;
	}
	return (idx);
}

int	is_matched(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (FALSE);
		i++;
	}
	return (TRUE);
}
