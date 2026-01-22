/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 00:14:31 by ayamhija          #+#    #+#             */
/*   Updated: 2026/01/23 00:14:45 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*join_with_space(char *result, char *arg, int add_space)
{
	char	*tmp;

	tmp = ft_strjoin(result, arg);
	free(result);
	if (!tmp)
		return (NULL);
	result = tmp;
	if (add_space)
	{
		tmp = ft_strjoin(result, " ");
		free(result);
		if (!tmp)
			return (NULL);
		result = tmp;
	}
	return (result);
}

static char	*join_arguments(int argc, char **argv)
{
	int		i;
	char	*result;

	result = ft_strdup("");
	if (!result)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		result = join_with_space(result, argv[i], (i != argc - 1));
		if (!result)
			return (NULL);
		i++;
	}
	return (result);
}

char	**split_and_join_args(int argc, char **argv)
{
	char	*joined;
	char	**split;

	joined = join_arguments(argc, argv);
	if (!joined)
		return (NULL);
	split = ft_split(joined, ' ');
	free(joined);
	return (split);
}

int	count_split_args(char **split_args)
{
	int	count;

	count = 0;
	while (split_args[count])
		count++;
	return (count);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
