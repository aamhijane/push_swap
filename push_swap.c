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

void	push_swap(int *a)
{

}

int	main(int argc, char **argv)
{
	int	*a;
	int	top;

	if (is_empty(argc, argv))
		return (FALSE);
	top = -1;
	a = extract_args(argc, argv, &top);
	if (!a)
		return (FALSE);
	push_swap(a);
	destroy_stack(a);
	return (FALSE);
}
