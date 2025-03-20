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

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str)
	{
		if (*str == (char) c)
			return (str);
		str++;
	}
	if (!c)
		return (str);
	return (NULL);
}
/*
int main()
{
	printf("%s\n", ft_strchr("tripouille", 'z'));
}
*/
