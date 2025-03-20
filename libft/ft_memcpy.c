/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsilva-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:31:55 by vsilva-r          #+#    #+#             */
/*   Updated: 2024/03/04 20:31:59 by vsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;

	if (!dest && !src && n)
		return (NULL);
	s = (char *)src;
	d = (char *)dest;
	while (n--)
	{
		*d++ = *s++;
	}
	return (dest);
}

/*
#include <stdio.h>
int main()
{
	char	a[] = "lixo";
	//char	b[] = "";
	//printf("%p, %p\n", a, b);
	printf("%s\n",(char *) ft_memcpy(a + 2, a, 4)-3);
	printf("%s\n",(char *) ft_memcpy(a + 2, NULL, 0)-3);	
}

//	ox89897		&b		ox68999		&a
//	...19a		b		...19b		a
//	\0		*b		lixoo\0		*a
*/
