/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 00:20:08 by ayamhija          #+#    #+#             */
/*   Updated: 2026/01/23 00:20:24 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_sort_algorithm(t_stack *a, t_stack *b)
{
	if (a->size <= 5)
		sort_small(a, b);
	else
		turk_sort(a, b);
}

static int	init_and_parse(char **split_args, int total_nums,
				t_stack **a, t_stack **b)
{
	*a = init_stack(total_nums);
	*b = init_stack(total_nums);
	if (!*a || !*b)
	{
		free_split(split_args);
		free_and_exit(*a, *b, 1);
		return (0);
	}
	if (!parse_split_args(split_args, total_nums, *a))
	{
		free_split(split_args);
		free_and_exit(*a, *b, 1);
		return (0);
	}
	return (1);
}

static int	validate_and_init(int argc, char **argv, char ***split_args)
{
	int	total_nums;

	*split_args = split_and_join_args(argc, argv);
	if (!*split_args)
	{
		print_error();
		return (0);
	}
	total_nums = count_split_args(*split_args);
	if (total_nums == 0 || !validate_split_args(*split_args, total_nums))
	{
		free_split(*split_args);
		print_error();
		return (0);
	}
	return (total_nums);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**split_args;
	int		total_nums;

	if (argc < 2)
		return (0);
	total_nums = validate_and_init(argc, argv, &split_args);
	if (!total_nums)
		return (1);
	if (!init_and_parse(split_args, total_nums, &a, &b))
		return (1);
	free_split(split_args);
	if (is_sorted(a))
	{
		free_and_exit(a, b, 0);
		return (0);
	}
	index_stack(a);
	choose_sort_algorithm(a, b);
	free_and_exit(a, b, 0);
	return (0);
}
