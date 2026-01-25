/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:08:31 by ayamhija          #+#    #+#             */
/*   Updated: 2026/01/25 19:08:39 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	execute_operation(char *op, t_stack *a, t_stack *b)
{
	if (ft_strcmp(op, "sa\n") == 0)
		sa(a, false);
	else if (ft_strcmp(op, "sb\n") == 0)
		sb(b, false);
	else if (ft_strcmp(op, "ss\n") == 0)
		ss(a, b, false);
	else if (ft_strcmp(op, "pa\n") == 0)
		pa(a, b, false);
	else if (ft_strcmp(op, "pb\n") == 0)
		pb(a, b, false);
	else if (ft_strcmp(op, "ra\n") == 0)
		ra(a, false);
	else if (ft_strcmp(op, "rb\n") == 0)
		rb(b, false);
	else if (ft_strcmp(op, "rr\n") == 0)
		rr(a, b, false);
	else if (ft_strcmp(op, "rra\n") == 0)
		rra(a, false);
	else if (ft_strcmp(op, "rrb\n") == 0)
		rrb(b, false);
	else if (ft_strcmp(op, "rrr\n") == 0)
		rrr(a, b, false);
	else
		error_exit(a, b);
}

static void	read_and_execute(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		execute_operation(line, a, b);
		free(line);
		line = get_next_line(0);
	}
}

static t_stack	*init_stack_b(int size)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->array = malloc(sizeof(int) * size);
	if (!stack->array)
	{
		free(stack);
		return (NULL);
	}
	stack->size = 0;
	return (stack);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = parse_args(argc, argv);
	if (!a)
		return (0);
	b = init_stack_b(a->size);
	if (!b)
		error_exit(a, NULL);
	read_and_execute(a, b);
	if (is_sorted(a) && b->size == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free_stack(a);
	free_stack(b);
	return (0);
}
