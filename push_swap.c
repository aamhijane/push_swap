/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 20:17:52 by ayamhija          #+#    #+#             */
/*   Updated: 2026/01/06 20:19:21 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "push_swap.h"

void	push_swap(int argc, char **argv)
{
	// int	a[argc - 1];
	int	i;

	if (argc <= 1)
	{

		write(2, "Error\n", 6);
		return ;
	}
	i = 1;
	while (i < argc)
	{
		if (!is_num(argv[i]))
		{
			write(2, "Error\n", 6);
			return ;
		}
		ft_printf("%s\n", argv[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		push_swap(argc, argv);
	return (0);
}
