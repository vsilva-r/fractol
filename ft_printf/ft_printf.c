/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsilva-r <vsilva-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:00:17 by vsilva-r          #+#    #+#             */
/*   Updated: 2024/05/22 16:49:07 by vsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	iprintstring(char *str)
{
	if (!str)
		return (ft_iputstr("(null)"));
	else
		return (ft_iputstr(str));
}

static int	iprintpointer(void *pointer)
{
	if (!pointer)
		return (ft_iputstr("(nil)"));
	else
		return (ft_iputstr("0x") 
			+ ft_uputnbr_base((unsigned long) pointer, HEXL));
}

static int	printit(char format, va_list args)
{
	if ((format) == '%')
		return (ft_iputchar(format));
	else if (format == 'i' || format == 'd')
		return (ft_iputnbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_iputnbr(va_arg(args, unsigned int)));
	else if (format == 'o')
		return (ft_uputnbr_base(va_arg(args, unsigned int), OCT));
	else if (format == 'x')
		return (ft_uputnbr_base(va_arg(args, unsigned int), HEXL));
	else if (format == 'X')
		return (ft_uputnbr_base(va_arg(args, unsigned int), HEXU));
	else if (format == 'b')
		return (ft_iputbinary(va_arg(args, unsigned long)));
	else if (format == 'B')
		return (ft_iputnbinary(va_arg(args, unsigned long), 64));
	else if (format == 'c')
		return (ft_iputchar((char)va_arg(args, int)));
	else if (format == 's')
		return (iprintstring(va_arg(args, char *)));
	else if (format == 'p')
		return (iprintpointer(va_arg(args, void *)));
	return (ft_iputchar('%') + ft_iputchar(format));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		written;

	if (!format)
		return (-1);
	va_start(args, format);
	written = 0;
	while (*format)
	{
		if (*format == '%')
		{
			written += printit(*(++format), args);
		}
		else
			written += ft_iputchar(*format);
		format++;
	}
	va_end(args);
	return (written);
}
