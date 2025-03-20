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

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;

	dst = dest;
	if (src < dest)
	{
		while (n--)
			(dst)[n] = ((unsigned char *)src)[n];
	}
	else if (src > dest)
	{
		while (n--)
			*(dst)++ = *(unsigned char *)(src)++;
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
	printf("%s\n",(char *) ft_memmove(a +3, a, 4)-6	);	
}
*/
