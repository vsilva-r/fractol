/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsilva-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:05:13 by vsilva-r          #+#    #+#             */
/*   Updated: 2025/05/23 14:05:14 by vsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_no_event(t_fractal *fractol)
{
	static int	flag;

	flag = -1;
	if (magnitude(fractol->c) >= BOUND)
		flag *= 1;
	if (fractol->moving)
	{
		fractol->c.x += flag * (double)2 * (double)BOUND / (double)WID * 5;
		fractal_fade_r (fractol);
	}
	render_fractol (fractol);
	return (0);
}

int	mouse_handler(int keysym, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (keysym == Button5)
	{
		fractal->zoom *= 0.95;
	}
	if (keysym == Button4)
	{
		fractal->zoom /= 0.95;
	}
	render_fractol(fractal);
	return (-1);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	keys_1(keysym, fractal);
	keys_2(keysym, fractal);
	if (keysym == XK_Escape)
	{
		ft_printf("ESC pressed. \n");
		close_window(fractal);
	}
	render_fractol(fractal);
	return (-1);
}

int	close_window(t_fractal *fractal)
{
	ft_printf("Closing window. Bye!\n");
	mlx_destroy_image(fractal->connect, fractal->image);
	mlx_destroy_window(fractal->connect, fractal->window);
	mlx_destroy_display(fractal->connect);
	free(fractal->connect);
	exit(1);
	return (-1);
}
