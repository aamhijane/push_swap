/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 00:29:15 by ayamhija          #+#    #+#             */
/*   Updated: 2026/01/26 00:31:01 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_stack *stack, int argc, char **argv)
{
	int		i;
	int		idx;
	char	**split;

	i = argc - 1;
	idx = 0;
	while (i >= 1)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			error_exit(stack, NULL);
		if (!process_split_reverse(split, stack, &idx))
			error_exit(stack, NULL);
		free_split(split);
		i--;
	}
}

t_stack	*parse_args(int argc, char **argv)
{
	t_stack	*stack;
	int		count;

	if (argc < 2)
		return (NULL);
	count = count_numbers(argc, argv);
	if (count <= 0)
		error_exit(NULL, NULL);
	stack = malloc(sizeof(t_stack));
	if (!stack)
		error_exit(NULL, NULL);
	stack->array = malloc(sizeof(int) * count);
	if (!stack->array)
		error_exit(stack, NULL);
	stack->size = count;
	fill_stack(stack, argc, argv);
	if (has_duplicates(stack->array, stack->size))
		error_exit(stack, NULL);
	return (stack);
}
