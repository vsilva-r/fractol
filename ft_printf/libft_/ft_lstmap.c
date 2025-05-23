/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsilva-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:43:19 by vsilva-r          #+#    #+#             */
/*   Updated: 2024/05/02 17:45:13 by vsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*checkpoint;

	if (!(lst && f && del))
		return (NULL);
	newlst = ft_lstnew(f((*lst).content));
	while (lst->next)
	{
		lst = (*lst).next;
		checkpoint = ft_lstnew(f((*lst).content));
		if (!checkpoint)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, checkpoint);
	}
	return (newlst);
}
