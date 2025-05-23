/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uputnbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsilva-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:27:08 by vsilva-r          #+#    #+#             */
/*   Updated: 2024/05/21 19:27:18 by vsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

// This helper function is only here so that ft_putnbr_base doesn't calculate
// base_size on every iteration.
static int	write_that_shit(unsigned long nbr, char *base, int base_size)
{
	int		current;
	int		written;

	if (!nbr)
		return (0);
	current = nbr % base_size;
	nbr /= base_size;
	written = 0;
	if (current < 0)
	{
		written += write(1, "-", 1);
		current *= -1;
		nbr *= -1;
	}
	written += write_that_shit(nbr, base, base_size);
	written += write(1, &base[current], 1);
	return (written);
}

static int	check_base(char *base)
{
	int	i;
	int	j;

	if (!base)
		return (0);
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
	return (&base[i] - base);
}

// So ft_iputnbr_base checks the base for any problems and then it calls
// write_that_shit() to write it iteratively
int	ft_uputnbr_base(unsigned long int nbr, char *base)
{
	int	base_size;

	base_size = check_base(base);
	if (base_size < 2)
		return (0);
	if (nbr == 0)
		return (write(1, base, 1));
	else
		return (write_that_shit(nbr, base, base_size));
}
/*
int	main(void)
{
	printf(" %d\n", ft_iputnbr_base(-1, "0123456789"));
	printf(" %d\n", ft_iputnbr_base(INT_MIN, "0123456789abcdef"));
	printf(" %d\n", ft_iputnbr_base(INT_MIN, "0"));
	printf(" %d\n", ft_iputnbr_base(0, "01"));
	printf(" %d\n", ft_iputnbr_base(INT_MIN, "ponysuview"));
	return (0);
}
*/
