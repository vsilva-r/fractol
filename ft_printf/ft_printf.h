/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsilva-r <vsilva-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:59:02 by vsilva-r          #+#    #+#             */
/*   Updated: 2024/05/22 16:45:34 by vsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# define OCT "01234567"
# define HEXU "0123456789ABCDEF"
# define HEXL "0123456789abcdef"
# define BIN "01"

int	ft_printf(const char *format, ...);
int	ft_printf_bonus(const char *format, ...);
int	ft_iputstr(char *str);
int	ft_iputnbr_base(long int nbr, char *base);
int	ft_uputnbr_base(unsigned long nbr, char *base);
int	ft_iputnbr(long int nbr);
int	ft_iputbinary(unsigned long nbr);
int	ft_iputnbinary(unsigned long nbr, int nbits);
int	ft_iputchar(char c);

#endif