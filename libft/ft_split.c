/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsilva-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:32:22 by vsilva-r          #+#    #+#             */
/*   Updated: 2024/04/24 11:32:31 by vsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**init_array(char const *s, char c)
{
	size_t		array_size;
	char		**array;

	array_size = 1;
	while (*s == c && *s)
		s++;
	while (*s)
	{
		if (*++s == c || *s == 0)
			array_size += 1;
		while (*s == c && *s)
			s++;
	}
	array = ft_calloc(array_size, sizeof(char *));
	return (array);
}

static int	len_substr(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (!(*(s) == c || *s == 0))
	{
		len += 1;
		s++;
	}
	return (len);
}

static char	**free_all(char **array_ptr)
{
	while (*array_ptr)
	{
		free(*array_ptr);
		*array_ptr++ = NULL;
	}
	free(array_ptr);
	array_ptr = NULL;
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		k;

	if (!s)
		return (NULL);
	array = init_array(s, c);
	if (!array)
		return (NULL);
	k = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			array[k] = ft_substr(s, 0, len_substr(s, c));
		if (*s && !array[k])
			return (free_all(array));
		k++;
		s += len_substr(s, c);
	}
	return (array);
}
/*
void freeTab(char **tab)
{
	for (int i = 0; tab[i] != NULL; ++i)
		free(tab[i]);
	free(tab);
}

int main()
{

	char	*s = "Hey there friend";
	int	i = 0;
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		printf("%d, %s\n", len_substr(s + i, ' '), s + i);
		//array[k++] = ft_substr(s, i, len_substr(s, c));
		i += len_substr(s + i, ' ');
	}
	
	char	**array;
	
	array = ft_split("   Hey ther efriend ", '\0');
	for (int i = 0; array[i]; i++)
		printf("%p, %s, %d\n", array + i, array[i], *array[i]);
	freeTab(array);
}
*/
