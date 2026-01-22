/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 00:14:58 by ayamhija          #+#    #+#             */
/*   Updated: 2026/01/23 00:15:09 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long	to_long(const char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

int	has_duplicates(int *array, int size)
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
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_split_args(char **split_args, int size)
{
	int		i;
	long	num;

	i = 0;
	while (i < size)
	{
		if (!is_valid_number(split_args[i]))
			return (0);
		num = to_long(split_args[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

int	parse_split_args(char **split_args, int size, t_stack *a)
{
	int		i;
	long	num;

	i = 0;
	while (i < size)
	{
		num = to_long(split_args[i]);
		a->array[i] = (int)num;
		i++;
	}
	a->size = size;
	if (has_duplicates(a->array, a->size))
		return (0);
	return (1);
}
