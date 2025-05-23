/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsilva-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:29:37 by vsilva-r          #+#    #+#             */
/*   Updated: 2024/03/18 13:29:38 by vsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// space characters = [space] \f \n \r \t \v
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int	is_digit(char c, char *base)
{
	while (*base != c && *(base))
		base++;
	return (*(base));
}

int	valid_base(char *base)
{
	int	i;
	int	j;
	int	base_size;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	base_size = &base[i] - base;
	if (base_size < 2)
		return (0);
	return (base_size);
}

//	MUST CREATE HELPER FUNCTION TO REDUCE LINES
//	THIS FUNCTION WILL DO THE SPACES AND SIGNS
void	skip_spaces_signs(char **str, int *sign)
{
	while ((8 < **str && **str < 14) || **str == 32)
	{
		(*str)++;
	}
	while (**str == '+' || **str == '-')
	{
		if (**str == '-')
			*sign *= -1;
		(*str)++;
	}
}

int	ft_atoi_base(char *str, char *base)
{
	int	n;
	int	sign;
	int	base_size;
	int	i;

	base_size = valid_base(base);
	if (base_size < 2)
		return (0);
	sign = 1;
	n = 0;
	skip_spaces_signs(&str, &sign);
	while (is_digit(*str, base))
	{
		i = 0;
		while (*str != base[i])
			i++;
		n *= base_size;
		n += i;
		str++;
	}
	return (n * sign);
}
/*
int main()
{
	printf("\n%d", ft_atoi_base(" \f\n\v --+-2147483648 atoi", "0123456789"));
}
*/
