/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsilva-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:51:11 by vsilva-r          #+#    #+#             */
/*   Updated: 2024/03/18 14:51:12 by vsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	size_t			dst_len;
	size_t			src_len;

	if (!dst && !size)
		return (0);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size < dst_len + 1)
		return (src_len + size);
	i = 0;
	while ((i < (size - dst_len - 1)) && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}
/*
int	main()
{
	char dest[] = "Shit";
	char src[] = "Fucking";
//	char *destp = dest;

	ft_putnbr_fd(ft_strlcat(dest, src, 6), 1); ft_putstr("\n");
	ft_putstr(src); ft_putstr("\n");
	ft_putstr(dest);
}
*/
