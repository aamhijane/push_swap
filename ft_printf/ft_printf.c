/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:04:57 by ayamhija          #+#    #+#             */
/*   Updated: 2025/11/19 16:30:49 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print(const char *format, va_list args, int *count)
{
	if (*format == '%')
		ft_putchar(*format, count);
	else if (*format == 'c')
		ft_putchar((char)va_arg(args, int), count);
	else if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (*format == 'u')
		ft_putnbr_unsigned(va_arg(args, unsigned int), count);
	else if (*format == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (*format == 'p')
		ft_print_addr(va_arg(args, void *), count);
	else if (*format == 'x')
		ft_print_hex(va_arg(args, unsigned int), count, 0);
	else if (*format == 'X')
		ft_print_hex(va_arg(args, unsigned int), count, 1);
	else
	{
		ft_putchar('%', count);
		ft_putchar(*format, count);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*(format + 1) == '\0')
		{
			if (*format == '%')
				return (-1);
			ft_putchar(*format, &count);
			break ;
		}
		if (*format == '%')
			ft_print(++format, args, &count);
		else
			ft_putchar(*format, &count);
		format++;
	}
	va_end(args);
	return (count);
}
