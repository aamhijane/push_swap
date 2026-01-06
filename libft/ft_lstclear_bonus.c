/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 20:38:10 by ayamhija          #+#    #+#             */
/*   Updated: 2025/11/09 20:39:08 by ayamhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next_node;

	if (lst && del)
	{
		while (*lst != NULL)
		{
			next_node = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = next_node;
		}
	}
}
