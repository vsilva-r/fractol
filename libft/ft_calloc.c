/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsilva-r <vsilva-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:15:21 by vsilva-r          #+#    #+#             */
/*   Updated: 2024/04/23 15:06:11 by vsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*ptr;
	size_t		full_size;

	full_size = nmemb * size;
	if (size && (full_size / size) != nmemb)
		return (NULL);
	ptr = malloc(full_size);
	if (!ptr)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (ptr);
	ft_memset(ptr, 0, full_size);
	return (ptr);
}

/*
#include <stdio.h>
int main()
{
	void *p = calloc(0, -5);
	printf("%p\n", p);
	free(p);
}
*/
