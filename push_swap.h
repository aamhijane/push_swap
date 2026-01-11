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
#include "libft/libft.h"
#include <stdio.h>

#define TRUE 1
#define FALSE 0

// void	push_swap(int argc, char **argv);
void	error();
void	fill_stack(int, char **);
void	free_allocated_stack(char **);
int	stack_size(char **);
int	is_empty(int, char **);
int	is_matched(char *, char *);
int	is_validate(char **, size_t);
char	**split_arguments(char **, int);
#endif
