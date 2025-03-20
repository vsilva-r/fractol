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

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*haystack;
	char	*needle;

	haystack = (char *)big;
	needle = (char *)little;
	if (*little == '\0')
		return (haystack);
	i = 0;
	while ((haystack || len) && haystack[i] && i < len)
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
/*
#include <limits.h>
#include <bsd/string.h>
int main()
{
	char *haystack = NULL;
	char needle[10] = "lol";
	//achar * empty = (char*)"";
	printf("%s\n", ft_strnstr(haystack, needle, 0));
//	printf("%s\n", strnstr(haystack, needle, 0));
}
*/
