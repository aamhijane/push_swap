/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:21:41 by ayamhija          #+#    #+#             */
/*   Updated: 2026/01/25 19:21:47 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int	*array;
	int	size;
}	t_stack;

t_stack	*parse_args(int argc, char **argv);
void	error_exit(t_stack *a, t_stack *b);
void	free_stack(t_stack *stack);
void	free_split(char **split);
bool	is_valid_number(char *str);
long	ft_atol(char *str);
int		count_numbers(int argc, char **argv);
bool	validate_and_convert(char *str, int *num);

void	sa(t_stack *a, bool print);
void	sb(t_stack *b, bool print);
void	ss(t_stack *a, t_stack *b, bool print);
void	pa(t_stack *a, t_stack *b, bool print);
void	pb(t_stack *a, t_stack *b, bool print);
void	ra(t_stack *a, bool print);
void	rb(t_stack *b, bool print);
void	rr(t_stack *a, t_stack *b, bool print);
void	rra(t_stack *a, bool print);
void	rrb(t_stack *b, bool print);
void	rrr(t_stack *a, t_stack *b, bool print);

bool	is_sorted(t_stack *stack);
int		ft_strcmp(const char *s1, const char *s2);

#endif
