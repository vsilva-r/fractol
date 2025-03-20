/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsilva-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:46:07 by vsilva-r          #+#    #+#             */
/*   Updated: 2024/04/24 11:46:07 by vsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_number_len(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len += 1;
	while (n)
	{
		len += 1;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t			len;
	unsigned int	number;
	char			*string;

	len = get_number_len(n);
	if (n <= 0)
		number = -n;
	else
		number = n;
	string = (char *)ft_calloc(len + 1, sizeof(char));
	if (!string)
		return (NULL);
	if (number == 0)
	{
		string[0] = '0';
		return (string);
	}
	while (number)
	{
		string[--len] = (char)(number % 10) + '0';
		number /= 10;
	}
	if (len > 0)
		string[--len] = '-';
	return (string);
}
