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

void	extract_argument(char *str)
{
	int i = 0;
	size_t len = ft_strlen(str);

	while (i < len)
	{	
		if (str[i] == ' ')
			str[i] = '\0';
		i++;
	}

	ft_printf("%d\n", ft_atoi(str));
}
