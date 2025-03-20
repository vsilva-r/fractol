/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsilva-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:13:44 by vsilva-r          #+#    #+#             */
/*   Updated: 2024/03/11 17:13:45 by vsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return ((32 <= c) && (c <= 126));
}
/*
int	main()
{
	printf("\n%d\n", ft_str_is_printable("\40a ate z\176"));
	printf("\n%d\n", ft_str_is_printable("\177"));
	printf("\n%d\n", ft_str_is_printable("\37"));
	printf("\n%d\n", ft_str_is_printable(""));
}
*/
