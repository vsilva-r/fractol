/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsilva-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:44:58 by vsilva-r          #+#    #+#             */
/*   Updated: 2024/05/02 17:44:59 by vsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
int main()
{
	t_list *l = ft_lstnew(NULL);
	t_list *n = NULL;
	printf("%d\n", l == n);
	printf("%d, %d\n", *(int *)l, *(int *)n);
	
	//printf("%s\n", (char *)l->content);
	
	//ft_lstadd_back(&l, ft_lstnew(NULL));
	//printf("%s\n", (char *)ft_lstlast(l)->content);
	
	ft_lstclear(&l, free);
	ft_lstclear(&n, free);
}
*/
