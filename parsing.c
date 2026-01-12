/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:22:05 by ayamhija          #+#    #+#             */
/*   Updated: 2026/01/07 20:22:29 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*join_arguments(char **arguments, int size)
{
	
	int	i;
	char	*result;
	char	*tmp;

	result = ft_strdup("");
	i = 1;
	while (i <= size - 1 && arguments[i] != NULL)
	{
		tmp = ft_strjoin(result, arguments[i]);
		free(result);
		if (!tmp)
			return (NULL);
		result = tmp;
		if (i != size - 1)
		{
			tmp = ft_strjoin(result, " ");
			free(result);
			if (!tmp)
				return (NULL);
			result = tmp;
		}
		i++;
	}
	return (result);
}

static char	**split_arguments(char **arguments, int size)
{
	char	*join_args;
	char	**split_args;

	join_args = join_arguments(arguments, size);
	if (!join_args)
		return (NULL);
	split_args = ft_split(join_args, ' ');
	free(join_args);
	if (!split_args)
		return (NULL);
	return (split_args);
}

int	*extract_args(int argc, char **argv, int *top)
{
	char	**split_args;
	size_t	size;
	size_t	i;
	int	*a;

	split_args = split_arguments(argv, argc);
	if (!split_args)
		return (NULL);
	size = stack_size(split_args);
	if (!is_validate(split_args, size))
	{
		destroy_double_stack((void **)split_args);
		error();
	}
	a = create_stack(size);
	if (!a)
	{
		destroy_double_stack((void **)split_args);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		a[i] = ft_atoi(split_args[i]);
		(*top)++;
		i++;
	}
	destroy_double_stack((void **)split_args);
	return (a);
}
