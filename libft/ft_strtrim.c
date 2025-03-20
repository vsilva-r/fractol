/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsilva-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:51:51 by vsilva-r          #+#    #+#             */
/*   Updated: 2024/04/24 09:51:52 by vsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	char	*strimmed;
	char	*back;

	if (!(s1 && set))
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
	{
		s1++;
	}
	back = (char *)s1 + ft_strlen(s1) - 1;
	while (*back && ft_strchr(set, *back) && back > s1)
	{
		back--;
	}
	len = back - s1 + 1;
	strimmed = ft_calloc(len + 1, sizeof(char));
	if (!strimmed)
		return (NULL);
	while (*s1 && s1 <= back)
	{
		*strimmed++ = *s1++;
	}
	return (strimmed - len);
}
/*
int main()
{
	printf("%s\n", ft_strtrim(NULL, ""));
}
*/
