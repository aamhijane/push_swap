/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 21:58:58 by ayamhija          #+#    #+#             */
/*   Updated: 2025/11/16 21:59:37 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int num, int *count)
{
	if (num == -2147483648)
	{
		ft_putstr("-2147483648", count);
		return ;
	}
	if (num < 0)
	{
		num = -num;
		ft_putchar('-', count);
	}
	if (num > 9)
		ft_putnbr(num / 10, count);
	ft_putchar((num % 10) + '0', &(*count++));
}

void	ft_putnbr_unsigned(unsigned int num, int *count)
{
	if (num > 9)
		ft_putnbr_unsigned(num / 10, count);
	ft_putchar((num % 10) + '0', &(*count++));
}
