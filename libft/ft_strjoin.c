/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsilva-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:32:53 by vsilva-r          #+#    #+#             */
/*   Updated: 2024/04/24 09:32:54 by vsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Boss era voltar e fazer isto com as listas do Bonus part

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*newstr;

	if (!(s1 && s2))
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	newstr = ft_calloc(len + 1, sizeof(char));
	if (!newstr)
		return (NULL);
	while (*s1)
		*newstr++ = *s1++;
	while (*s2)
		*newstr++ = *s2++;
	return (newstr - len);
}
