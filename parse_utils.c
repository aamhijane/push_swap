/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:27:48 by ayamhija          #+#    #+#             */
/*   Updated: 2026/01/26 00:31:09 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	has_duplicates(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

bool	validate_and_convert(char *str, int *num)
{
	long	n;

	if (!is_valid_number(str))
		return (false);
	n = ft_atol(str);
	if (n > INT_MAX || n < INT_MIN)
		return (false);
	*num = (int)n;
	return (true);
}

int	count_split_numbers(char **split)
{
	int	count;

	count = 0;
	while (split[count])
		count++;
	return (count);
}

bool	process_split_reverse(char **split, t_stack *stack, int *idx)
{
	int	j;
	int	count;

	count = count_split_numbers(split);
	j = count - 1;
	while (j >= 0)
	{
		if (!validate_and_convert(split[j], &stack->array[*idx]))
		{
			free_split(split);
			return (false);
		}
		(*idx)++;
		j--;
	}
	return (true);
}
