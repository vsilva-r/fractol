/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsilva-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:16:28 by vsilva-r          #+#    #+#             */
/*   Updated: 2024/03/19 12:16:30 by vsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	i = ft_strlen(s) + 1;
	dest = (char *)ft_calloc(i, sizeof(char));
	while (--i >= 0 && dest)
	{
		dest[i] = s[i];
	}
	return (dest);
}
/*
int	main()
{
	char *str1 = "O que quiseres\0teste";
	char *ptr = ft_strdup(str1);
	
	printf("%p, %p, %s\n", str1, ptr, ptr);
	free (ptr); 
}
*/
