/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_recursive.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsilva-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:01:18 by vsilva-r          #+#    #+#             */
/*   Updated: 2024/03/17 15:01:21 by vsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <limits.h>

// This helper function is only here so that ft_putnbr_base doesn't calculate 
// base_size on every iteration.
void	write_that_shit(long int nbr, char *base, int base_size)
{
	int		current;
	char	current_char;

	if (!nbr)
		return ;
	current = nbr % base_size;
	nbr /= base_size;
	if (current < 0)
	{
		write(1, "-", 1);
		current *= -1;
		nbr *= -1;
	}
	write_that_shit(nbr, base, base_size);
	current_char = base[current];
	write(1, &current_char, 1);
}

// So ft_putnbr_base checks the base for any problems and then it calls 
// write_that_shit() to write it iteratively
void	ft_putnbr_base(int nbr, char *base)
{
	int	base_size;
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return ;
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return ;
			j++;
		}
		i++;
	}
	base_size = &base[i] - base;
	if (base_size < 2)
		return ;
	if (nbr == 0)
		write(1, "0", 1);
	write_that_shit(nbr, base, base_size);
}
/*
int	main(void)
{
	ft_putnbr_base(INT_MIN, "0123456789abcdef");
	write(1, "\n", 1);
	ft_putnbr_base(INT_MIN, "0");
	write(1, "\n", 1);
	ft_putnbr_base(0, "01");
	write(1, "\n", 1);
	ft_putnbr_base(INT_MIN, "ponysuview");
	return (0);
}
*/
