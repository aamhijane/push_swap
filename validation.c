/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:01:34 by ayamhija          #+#    #+#             */
/*   Updated: 2026/01/07 20:01:57 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_number(char *argument)
{
	int	i;

	i = 0;
	while (argument[i] && argument[i] == '-')
		i++;
	if (i > 1 || (i == 1 && ft_strlen(argument) == 1))
		return (FALSE);
	if (i == 1 && argument[i] == '0')
		return (FALSE);
		
	while (argument[i])
	{
		if (!ft_isdigit(argument[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static	int	is_duplicate(char **arguments, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_strlen(arguments[i]) == ft_strlen(arguments[j]))
			{
				if (is_matched(arguments[i], arguments[j]))
					return (TRUE);
			}
			j++;
		}
		i++;
	}
	return (FALSE);
}

static long	is_limit(char *argument)
{
	long	res;
	int		sign;
	size_t	i;

	res = 0;
	sign = 1;
	i = 0;
	if (argument[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (argument[i])
	{
		res *= 10;
		res += argument[i] - 48;
		i++;
	}
	res *= sign;
	if (res > 2147483647 || res < -2147483648)
		return (TRUE);
	return (FALSE);
		
}

int	is_empty(int argc, char **argv)
{
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (TRUE);
	return (FALSE);
}

int	is_validate(char **arguments, size_t size)
{
	size_t	i;
	int	is_dup;

	is_dup = is_duplicate(arguments, size);
	i = 0;
	while (size > i)
	{
		if (!is_number(arguments[i]) || is_limit(arguments[i]))
			return (FALSE);
		i++;
	}
	if (is_dup)
		return (FALSE);
	return (TRUE);
}
