/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:06:41 by ayamhija          #+#    #+#             */
/*   Updated: 2025/11/16 22:06:14 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_print_addr(void *addr, int *count);
void	ft_print_hex(unsigned long n, int *count, unsigned int is_upper);
void	ft_putstr(const char *s, int *count);
void	ft_putnbr(int num, int *count);
void	ft_putnbr_unsigned(unsigned int num, int *count);
void	ft_putchar(const char c, int *count);
size_t	ft_strlen(const char *s);
#endif
