/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:15:06 by ayamhija          #+#    #+#             */
/*   Updated: 2025/11/04 16:24:54 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digits_in_number(int n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*fill_buffer(size_t digits_count, long int value, int sign)
{
	char	*buffer;
	size_t	buffer_idx;

	buffer = malloc(sizeof(char) * (digits_count + 1));
	if (buffer == NULL)
		return (NULL);
	buffer_idx = digits_count - 1;
	if (value == 0)
		buffer[buffer_idx] = '0';
	else
	{
		while (value != 0)
		{
			buffer[buffer_idx] = (value % 10) + '0';
			value /= 10;
			buffer_idx--;
		}
	}
	if (sign == -1)
		buffer[0] = '-';
	buffer[digits_count] = '\0';
	return (buffer);
}

char	*ft_itoa(int n)
{
	size_t		digits_count;
	int			sign;
	long int	value;

	digits_count = count_digits_in_number(n);
	sign = 1;
	value = n;
	if (value < 0)
	{
		sign = -1;
		digits_count++;
		value = -value;
	}
	return (fill_buffer(digits_count, value, sign));
}
