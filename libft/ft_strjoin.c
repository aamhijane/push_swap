/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:32:53 by ayamhija          #+#    #+#             */
/*   Updated: 2025/11/01 17:46:10 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_join(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*s;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s = malloc(s1_len + s2_len + 1);
	if (s == NULL)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		s[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
	{
		s[s1_len + i] = s2[i];
		i++;
	}
	s[s1_len + s2_len] = '\0';
	return (s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	return (ft_join(s1, s2));
}
