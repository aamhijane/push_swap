/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 22:59:17 by ayamhija          #+#    #+#             */
/*   Updated: 2026/01/06 23:00:03 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdio.h>

# define TRUE 1
# define FALSE 0

void	error(void);

void	destroy_double_stack(void **stack);
void	destroy_stack(void *stack);
void	fill_stack(int *a, char **split_args, size_t size, int *top);

int		stack_size(char **arguments);
int		*create_stack(size_t size);
int		*extract_args(int argc, char **argv, int *top);

int		is_empty(int argc, char **argc);
int		is_matched(char *s1, char *s2);
int		is_validate(char **split_args, size_t size);

void	push_swap(int *a);
#endif
