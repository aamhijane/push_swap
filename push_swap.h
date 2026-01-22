/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 00:04:15 by ayamhija          #+#    #+#             */
/*   Updated: 2026/01/23 00:04:30 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int	*array;
	int	size;
	int	capacity;
}	t_stack;

typedef struct s_cost
{
	int	cost_a;
	int	cost_b;
	int	total;
	int	use_rr;
	int	use_rrr;
}	t_cost;

void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stack *a, t_stack *b);

t_stack		*init_stack(int capacity);
void		free_stack(t_stack *stack);
void		free_and_exit(t_stack *a, t_stack *b, int exit_code);
int			is_empty(t_stack *stack);
int			is_sorted(t_stack *stack);
int			find_min(t_stack *stack);
int			find_max(t_stack *stack);
int			find_position(t_stack *stack, int value);

char		**split_and_join_args(int argc, char **argv);
int			count_split_args(char **split_args);
void		free_split(char **split);
int			validate_split_args(char **split_args, int size);
int			parse_split_args(char **split_args, int size, t_stack *a);
int			is_valid_number(char *str);
long		to_long(const char *str);
int			has_duplicates(int *array, int size);

void		sort_three(t_stack *a);
void		sort_small(t_stack *a, t_stack *b);
void		turk_sort(t_stack *a, t_stack *b);
void		choose_sort_algorithm(t_stack *a, t_stack *b);
void		final_rotation(t_stack *a);

void		index_stack(t_stack *stack);

t_cost		calculate_cost(t_stack *a, t_stack *b, int pos_b);
void		finalize_cost(t_cost *cost);
int			find_cheapest(t_stack *a, t_stack *b);
int			find_target_pos(t_stack *a, int value);

void		execute_move(t_stack *a, t_stack *b, int pos_b);
void		rotate_a_to_pos(t_stack *a, int target_pos);
void		rotate_b_to_pos(t_stack *b, int target_pos);

void		print_error(void);

char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *s);

#endif
