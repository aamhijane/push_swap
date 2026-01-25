/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:27:28 by ayamhija          #+#    #+#             */
/*   Updated: 2025/11/02 16:15:21 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	llen;
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	llen = ft_strlen(little);
	i = 0;
	while (i < len && big[i] != '\0' && i + llen <= len)
	{
		j = 0;
		while (j < llen && big[i + j] == little[j])
			j++;
		if (j == llen)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
