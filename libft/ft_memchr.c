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

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *) s;
	c = (unsigned char) c;
	while (n--)
	{
		if (*str++ == c)
			return (str - 1);
	}
	return (NULL);
}
/*
int main()
{
	printf("%s\n", (char *)memchr(NULL, 'z', 20));
	printf("%s\n", (char *)ft_memchr(NULL, 'z', 20));
}
*/
