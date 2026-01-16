/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 20:17:52 by ayamhija          #+#    #+#             */
/*   Updated: 2026/01/12 22:20:28 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test(int *a, int *b, int *a_top, int *b_top)
{
	int	i;
	int	index;

	// stack a
	index = idx_of_large(a, a_top);
	printf("LARGE NUMBER IS: %d\n", a[index]);
	// i = *a_top;
	// while (i >= 0)
	// {
	// 	printf("a[%d] = %d\n", i, a[i]);
	// 	i--;
	// }
	//
	// // stack b
	// i = *b_top;
	// while (i >= 0)
	// {
	// 	printf("b[%d] = %d\n", i, b[i]);
	// 	i--;
	// }

}

void	push_swap(int *a)
{
	printf("%p\n", a);
}

int	main(int argc, char **argv)
{
	int		*a;
	int		*b;
	int		a_top;
	int		b_top;

	if (is_empty(argc, argv))
		return (FALSE);
	a_top = -1;
	b_top = -1;
	a = extract_args(argc, argv, &a_top);
	b = create_stack(a_top + 1);
	if (!a || !b)
		return (FALSE);
	push_swap(a);
	test(a, b, &a_top, &b_top);
	destroy_stack(a);
	destroy_stack(b);
	return (FALSE);
}
