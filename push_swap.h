/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:28:04 by ayamhija          #+#    #+#             */
/*   Updated: 2026/01/25 18:28:13 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
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
int		count_split_numbers(char **split);
int		count_numbers(int argc, char **argv);
bool	validate_and_convert(char *str, int *num);
bool	has_duplicates(int *array, int size);
bool	process_split_reverse(char **split, t_stack *stack, int *idx);

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

void	sort_three(t_stack *a);
void	sort_small(t_stack *a, t_stack *b);
void	turk_sort(t_stack *a, t_stack *b);

void	find_cheapest(t_stack *a, t_stack *b, int *cost_a, int *cost_b);
bool	is_sorted(t_stack *stack);
int		find_min_index(t_stack *stack);
int		find_max_index(t_stack *stack);
int		abs_val(int n);
int		find_target_in_a(t_stack *a, int b_value);
int		calc_moves_a(int target_idx, int size_a);
int		calc_moves_b(int b_idx, int size_b);
int		calc_total_cost(int cost_a, int cost_b);

#endif
