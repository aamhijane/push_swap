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

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "push_swap.h"

// void	push_swap(int argc, char **argv) {}

int	main(int argc, char **argv)
{
	int	i;
	int	count_arg;
	int	stack[4];

	stack[0] = 2;
	stack[1] = 2;
	stack[2] = 3;
	stack[3] = 4;

	i = 1;
	count_arg = 0;

	ft_printf("NUMBER OF ARGC: %d\n", argc);
	while (argc > i)
	{
		count_arguments(argv[i], &count_arg);
		i++;
	}
	ft_printf("NUMBER OF ARGUMENTS: %d\n", count_arg);
	if (is_duplicate(stack, 4))
		ft_printf("IS DUPLICATED");
	else
		ft_printf("IS NOT DUPLICATED");
	// extract_argument(argv[1]);
	return (FALSE);
}
