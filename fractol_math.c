/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsilva-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:39:43 by vsilva-r          #+#    #+#             */
/*   Updated: 2025/05/23 12:39:44 by vsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	compute(t_complex z, t_complex c)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y) + c.x;
	result.y = 2 * z.x * z.y + c.y;
	return (result);
}

double	magnitude(t_complex z)
{
	double	abs;

	abs = sqrt((z.x * z.x) + (z.y * z.y));
	return (abs);
}
