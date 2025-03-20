/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsilva-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:30:58 by vsilva-r          #+#    #+#             */
/*   Updated: 2024/04/08 19:33:23 by vsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	c %= 256;
	p = NULL;
	while (*s)
	{
		if (*s == c)
			p = (char *)s;
		s++;
	}
	if (!c)
		p = (char *)s;
	return (p);
}
/*
#include <stdio.h>
int main()
{
	printf("%s\n", ft_strrchr("tripoulle", 't' + 256));
}
*/
