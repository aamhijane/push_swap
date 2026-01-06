/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:22:32 by ayamhija          #+#    #+#             */
/*   Updated: 2025/11/01 15:52:14 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*sr;
	char		*ds;
	size_t		i;

	ds = (char *)dest;
	sr = (const char *)src;
	if (ds < sr)
	{
		i = 0;
		while (i < n)
		{
			ds[i] = sr[i];
			i++;
		}
	}
	else if (ds > sr)
	{
		i = n;
		while (i > 0)
		{
			i--;
			ds[i] = sr[i];
		}
	}
	return (dest);
}
