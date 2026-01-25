/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 21:59:59 by ayamhija          #+#    #+#             */
/*   Updated: 2025/10/31 22:17:09 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*s_one;
	unsigned char		*s_two;
	size_t				i;

	s_one = (unsigned char *)s1;
	s_two = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s_one[i] != s_two[i])
			return (s_one[i] - s_two[i]);
		i++;
	}
	return (0);
}
