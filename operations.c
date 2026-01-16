/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:24:54 by ayamhija          #+#    #+#             */
/*   Updated: 2026/01/07 19:24:55 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int *a, int *a_top, int show)
{
	int	tmp;

	tmp = a[*a_top];
	a[*a_top] = a[*a_top - 1];
	a[*a_top - 1] = tmp;
	if (show)
		write(1, "sa\n", 3);
}

void	sb(int *b, int *b_top, int show)
{
	int	tmp;

	tmp = b[*b_top];
	b[*b_top] = b[*b_top - 1];
	b[*b_top - 1] = tmp;
	if (show)
		write(1, "sb\n", 3);
}

void	ss(int *a, int *b, int *a_top, int *b_top)
{
	sa(a, a_top, FALSE);
	sb(b, b_top, FALSE);
	write(1, "ss\n", 3);
}

void	pa(int *a, int *b, int *a_top, int *b_top, int show)
{
	if (*b_top == -1)
		return ;
	a[++(*a_top)] = b[*b_top];
	(*b_top)--;
	if (show)
		write(1, "pa\n", 3);
}

void	pb(int *a, int *b, int *a_top, int *b_top, int show)
{
	if (*a_top == -1)
		return ;
	b[++(*b_top)] = a[*a_top];
	(*a_top)--;
	if (show)
		write(1, "pb\n", 3);
}

void	ra(int *a, int *a_top, int show)
{
	int	tmp;
	int	i;

	if (*a_top <= 0)
		return ;
	i = *a_top;
	tmp = a[*a_top];
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = tmp;
	if (show)
		write(1, "ra\n", 3);
}

void	rb(int *b, int *b_top, int show)
{
	int	tmp;
	int	i;

	if (*b_top <= 0)
		return ;
	i = *b_top;
	tmp = b[*b_top];
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = tmp;
	if (show)
		write(1, "rb\n", 3);
}

void	rr(int *a, int *b, int *a_top, int *b_top)
{
	ra(a, a_top, FALSE);
	rb(b, b_top, FALSE);
	write(1, "rr\n", 3);
}

void	rra(int *a, int *a_top, int show)
{
	int	tmp;
	int	i;

	if (*a_top <= 0)
		return ;
	i = 0;
	tmp = a[0];
	while (i < *a_top)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[*a_top] = tmp;
	if (show)
		write(1, "rra\n", 4);
}

void	rrb(int *b, int *b_top, int show)
{
	int	tmp;
	int	i;

	if (*b_top <= 0)
		return ;
	i = 0;
	tmp = b[0];
	while (i < *b_top)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[*b_top] = tmp;
	if (show)
		write(1, "rrb\n", 4);
}

void	rrr(int *a, int *b, int *a_top, int *b_top)
{
	rra(a, a_top, FALSE);
	rrb(b, b_top, FALSE);
	write(1, "rrr\n", 4);
}
