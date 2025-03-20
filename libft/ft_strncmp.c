/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsilva-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 19:17:11 by vsilva-r          #+#    #+#             */
/*   Updated: 2024/03/17 19:17:12 by vsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (--n && *str1 && *str2 == *str1)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
/*
int main()
{
	printf("%d\n", strncmp("1235", "1245", -6)); //-1
	printf("%d\n", strncmp("1245", "1235", -6)); //1
	printf("%d\n", strncmp("1235", "1245", -2)); //-1
	printf("%d\n", strncmp("1245", "1235", -2)); //1
	printf("%d\n", strncmp("1235", "1245", -1)); //-1
	printf("%d\n", strncmp("1245", "1235", -1)); //1
	printf("%d\n", strncmp("1235", "1245", 0));  //0
	printf("%d\n", strncmp("1245", "1235", 0));  //0
	printf("%d\n", strncmp("1235", "1245", 1));  	//0
	printf("%d\n", strncmp("1245", "1235", 1));	//0
	printf("%d\n", strncmp("1235", "1245", 2)); 	//0
	printf("%d\n", strncmp("1245", "1235", 2));	//0
	printf("%d\n", strncmp("1235", "1245", 3)); 	//-1
	printf("%d\n", strncmp("1245", "1235", 3));	//1
//	printf("%d\n", ft_strncmp("2234", "1235", -1000));
}
*/
