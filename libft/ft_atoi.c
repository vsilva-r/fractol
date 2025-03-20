/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsilva-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:46:04 by vsilva-r          #+#    #+#             */
/*   Updated: 2024/03/12 20:46:06 by vsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// space characters = [space] \f \n \r \t \v
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	is_space(char c)
{
	return ((8 < c && c < 14) || c == 32);
}

static int	is_digit(char c)
{
	return (47 < c && c < 58);
}

static int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

int	ft_atoi(const char *nptr)
{
	int	n;
	int	sign;

	sign = 1;
	n = 0;
	while (is_space(*nptr))
	{
		nptr++;
	}
	if (is_sign(*nptr))
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (is_digit(*nptr))
	{
		n *= 10;
		n += *nptr - 48;
		nptr++;
	}
	return (n * sign);
}
/*
int main()
{
	printf("%d\n", ft_atoi(" \f\f\v \n\v +2147483647 So, can you  atoi"));
	printf("%d\n", ft_atoi(" \f\f\v \n\v -2147483648 So, can you  atoi"));
	printf("%d\n", ft_atoi(" \f\f\v \n+2147483648 So, can you  atoi"));
	printf("%d\n", ft_atoi(" \f\f\v \n\v -21474836480 So, can you  atoi"));
}

//	-2147483648 INT_MIN
*/
