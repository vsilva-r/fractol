/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsilva-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:59:52 by vsilva-r          #+#    #+#             */
/*   Updated: 2024/03/10 18:00:21 by vsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Input size: 
	Return val: length of src
	Copy (up to) size-1 bytes from src and append NUL */

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	size_t			src_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while ((i < (size - 1)) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

/*
int	main()
{
	char src[] = "Fucking";
	char dest[] = "Shit";
//	char *destp = dest;
	
	ft_putnbr_fd(ft_strlcpy(dest, src, 0), 1); ft_putstr("\n");
	ft_putstr(src); ft_putstr("\n");
	ft_putstr(dest);
}
*/
