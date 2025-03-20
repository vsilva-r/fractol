/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsilva-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:26:11 by vsilva-r          #+#    #+#             */
/*   Updated: 2024/03/11 13:26:13 by vsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
/*
int	main()
{
	printf("\n%d\n", ft_str_is_alpha("AhGFHSJiZisnacz"));
	printf("%d, %s\n", ft_str_is_alpha("\100"), "\100");
	printf("%d, %s\n", ft_str_is_alpha("\133"), "\133");
	printf("%d, %s\n", ft_str_is_alpha("\140"), "\140");
	printf("%d, %s\n", ft_str_is_alpha("\173"), "\173");
}
*/
