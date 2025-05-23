/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsilva-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:47:30 by vsilva-r          #+#    #+#             */
/*   Updated: 2025/05/23 13:47:31 by vsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define COLORS_PHASE 0xffffff / MAX_COLORS

int	fractal_mlx_init(t_fractal *f)
{
	f->connect = mlx_init();
	if (!f->connect)
	{
		free(f->connect);
		return (-1);
	}
	f->window = mlx_new_window(f->connect, WID, HEI, "Fract'ol!");
	if (!f->window)
	{
		mlx_destroy_display(f->connect);
		free (f->connect);
		return (-1);
	}
	f->image = mlx_new_image(f->connect, WID, HEI);
	if (!f->image)
	{
		mlx_destroy_window(f->connect, f->window);
		mlx_destroy_display(f->connect);
		free (f->connect);
		return (-1);
	}
	f->pixels.ptr = mlx_get_data_addr(f->image, &f->pixels.bpp, \
							&f->pixels.line_length, &f->pixels.endian);
	return (0);
}

void	fractal_colors_init(t_fractal *fractal)
{
	int	i;
	int	j;

	fractal->colors[0] = (t_colorfade){0xff0000, 1, -1};
	i = 0;
	while (++i < MAX_COLORS)
	{
		fractal->colors[i] = fractal->colors[i - 1];
		j = 0;
		while (++j < COLORS_PHASE)
			fractal->colors[i] = colorfade_r(fractal->colors[i]);
	}
}

void	fractal_stats_init(t_fractal *fractal)
{
	fractal->mandelbrot = fractal->mandelbrot & 1;
	fractal->c.x = fractal->c_input.x;
	fractal->c.y = fractal->c_input.y;
	fractal->zoom = 1;
	fractal->translate = (t_complex){0, 0};
	fractal->moving = 0;
	fractal_colors_init(fractal);
}

int	fractal_init(t_fractal *fractol)
{
	fractal_stats_init(fractol);
	return (fractal_mlx_init(fractol));
}

void	hooks_init(t_fractal *f)
{
	mlx_hook(f->window,
		KeyPress,
		KeyPressMask,
		key_handler,
		f);
	mlx_mouse_hook(f->window,
		mouse_handler,
		f);
	mlx_hook(f->window,
		DestroyNotify,
		StructureNotifyMask,
		close_window,
		f);
	mlx_loop_hook(f->connect, handle_no_event, f);
}
