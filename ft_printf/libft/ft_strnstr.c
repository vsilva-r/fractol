/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsilva-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:50:58 by vsilva-r          #+#    #+#             */
/*   Updated: 2024/03/18 14:50:59 by vsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bsd/string.h> // compile with flag -lbsd 

static char	*actual_strnstr(char *haystack, char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return (haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] == haystack[i] && needle[j] && i < len)
		{
			j++;
			i++;
		}
		if (needle[j] == 0)
			return (haystack + i - j);
		else
			i -= j - 1;
	}
	return (NULL);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (!big || !little)
		return (NULL);
	return (actual_strnstr((char *)big, (char *)little, len));
}
/*
#include <limits.h>

int main()
{
	char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";
	//achar * empty = (char*)"";
	printf("%s\n", ft_strnstr(haystack, needle, -5));
	printf("%s\n", strnstr(haystack, needle, -5));
}
*/
