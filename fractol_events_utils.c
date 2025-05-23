/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsilva-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:27:30 by vsilva-r          #+#    #+#             */
/*   Updated: 2025/05/23 15:27:31 by vsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	keys_1(int keysym, t_fractal *fractal)
{
	if (keysym == XK_r)
		fractal_stats_init(fractal);
	if (keysym == XK_space)
		fractal->moving ^= 1;
	if (keysym == XK_0)
		fractal_fade_r(fractal);
	if (keysym == XK_9)
		fractal_fade_l(fractal);
	if (keysym == XK_u)
		fractal->c.x += (double)BOUND / (double)WID * 5;
	if (keysym == XK_k)
		fractal->c.x -= (double)BOUND / (double)WID * 5;
	if (keysym == XK_i)
		fractal->c.y += (double)BOUND / (double)HEI * 5;
	if (keysym == XK_j)
		fractal->c.y -= (double)BOUND / (double)HEI * 5;
	if (keysym == XK_m)
		fractal->mandelbrot ^= 1;
}

void	keys_2(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Left)
		fractal->translate.x -= 0.1;
	if (keysym == XK_Right)
		fractal->translate.x += 0.1;
	if (keysym == XK_Up)
		fractal->translate.y += 0.1;
	if (keysym == XK_Down)
		fractal->translate.y -= 0.1;
}
