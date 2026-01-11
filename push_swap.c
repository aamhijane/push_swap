/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 20:17:52 by ayamhija          #+#    #+#             */
/*   Updated: 2026/01/07 19:32:48 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**extract_args(int argc, char **argv)
{
	size_t	size;
	char	**split_args;

	if (is_empty(argc, argv))
		return (NULL);
	split_args = split_arguments(argv, argc);
	if (!split_args)
		return (NULL);
	size = stack_size(split_args);
	if (!is_validate(split_args, size))
		error();
	return (split_args);
}

int	main(int argc, char **argv)
{
	char	**ext_args;

	ext_args = extract_args(argc, argv);
	if (!ext_args)
		return (FALSE);
	free_allocated_stack(ext_args);
	return (FALSE);
}
