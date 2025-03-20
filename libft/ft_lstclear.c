/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsilva-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:43:19 by vsilva-r          #+#    #+#             */
/*   Updated: 2024/05/02 17:44:32 by vsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	if (*lst)
		ft_lstclear(&(**lst).next, del);
	ft_lstdelone(*lst, del);
	*lst = NULL;
}

/*	THIS OTHER WAY SUCKS
void	ft_lstclear (t_list **lst, void (*del)(void *))
{
	t_list	*last;

	while ((**lst).next)
	{
		last = ft_lstlast(*lst);
		(*del)(last->content);
		free(last);
	}
	*lst = NULL;
}
*/
