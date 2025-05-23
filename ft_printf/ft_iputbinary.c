/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iputbinary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsilva-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:54:59 by vsilva-r          #+#    #+#             */
/*   Updated: 2024/05/22 10:55:12 by vsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

// Writes the last nbits bits of the binary representation of the number nbr
// Returns the number of characters written.
int	ft_iputnbinary(unsigned long nbr, int nbits)
{
	int		i;
	int		written;

	written = 0;
	i = nbits - 1;
	while (i >= 0)
	{
		written += ft_iputchar((nbr & (1 << i--)));
		if (i % 4 == 3)
			written += ft_iputchar(' ');
	}
	return (written);
}

// Returns the minimum number of bits required for binary representation of n.
static int	get_nbr_len(unsigned long n)
{
	int	len;

	len = 0;
	while (n)
	{
		len += 1;
		n /= 2;
	}
	return (len);
}

// Writes the binary representation of nbr in groups of 4 bits.
// Returns the number of characters written.
int	ft_iputbinary(unsigned long nbr)
{
	int		i;
	int		written;

	written = 0;
	i = get_nbr_len(nbr) - 1;
	i += 3 - (i % 4);
	while (i >= 0)
	{
		written += ft_iputchar((nbr & (1 << i--)) + 33);
		if (i % 4 == 3)
			written += ft_iputchar(' ');
	}
	return (written);
}

// Test function for you to see the results :)
/*
int main()
{
	ft_printf("\t1: \t%b\n\t5: \t%b\n\t63: \t%b\n\n", 1, 5, 63);
	ft_printf("INT_MIN: \t%b\nINT_MAX: \t%b\n\t-2: \t%B\n\n", INT_MIN, INT_MAX, 2);
}
*/
/*
static int	write_that_shit(unsigned int nbr, int offset)
{
	int		current;
	int		written;
	
	if (!nbr)
		return (0);
	written = offset;
	current = nbr % 2 + 48;
	nbr /= 2;
	written += write_that_shit(nbr, 0);
	if ((written - (written / 5)) % 4 == 0)
		written += ft_iputchar(' ');
	written += write(1, &(current), 1);
	return (written);
}



int	ft_iputbinary(unsigned int nbr)
{
	int		written;
	int		offset;
	
	(void)get_nbr_len(nbr);
	if (!nbr)
		return (ft_iputchar('0'));
	offset = 0; //get_nbr_len(nbr) % 4;
	written = write_that_shit(nbr, offset);
	return (written - offset);
}
*/
