/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:22:05 by ayamhija          #+#    #+#             */
/*   Updated: 2026/01/07 20:22:29 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

static void	space_to_nterminate(char *str)
{
	int	i;
	size_t	len; 

	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{	
		if (str[i] == ' ')
			str[i] = '\0';
		i++;
	}
}

void	fill_static_stack(char *stack, int index, int element)
{
	stack[index] = element;
}

void	count_arguments(char *arg, int *count_arg)
{
	int	i;
	int	num;
	size_t	len;
	size_t	num_len;

	i = 0;
	len = ft_strlen(arg);
	space_to_nterminate(arg);
	while (i < len)
	{	
		while (arg[i] == '\0')
			i++;
		num = ft_atoi(arg + i);
		num_len = ft_strlen(ft_itoa(num));
		i = i + num_len;
		(*count_arg)++;
	}
}

void	extract_argument(char *str)
{
	int	i;
	int	num;
	size_t	len;
	size_t	num_len;

	i = 0;
	len = ft_strlen(str);
	space_to_nterminate(str);
	while (i < len)
	{	
		while (str[i] == '\0')
			i++;
		num = ft_atoi(str + i);

		// push to the stack
		// fill_static_stack(stack, j, num);

		num_len = ft_strlen(ft_itoa(num));
		i = i + num_len;
	}

}


























