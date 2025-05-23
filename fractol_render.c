/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsilva-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:39:53 by vsilva-r          #+#    #+#             */
/*   Updated: 2025/05/23 12:39:55 by vsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_pixel_put(int x, int y, t_pixels *img, int color)
{
	int	offset;

	offset = (y * img->line_length) + (x * (img->bpp / 8));
	*(unsigned int *)(img->ptr + offset) = color;
}

int	do_iterate(t_complex z, t_complex c, int max_iter, double bound)
{
	int	iter;

	iter = -1;
	while (++iter < max_iter)
	{
		z = compute(z, c);
		if (magnitude(z) > bound)
		{
			break ;
		}
	}
	return (iter);
}

t_complex	get_complex(double x, double y, t_fractal f)
{
	t_complex	z;

	z.x = (-BOUND + (x / WID) * 2 * BOUND) / f.zoom + f.translate.x;
	z.y = (BOUND - (y / HEI) * 2 * BOUND) / f.zoom + f.translate.y;
	return (z);
}

void	get_pixel_color(int x, int y, t_fractal *fractol)
{
	t_complex	z;
	int			iter;
	int			color;

	z = get_complex((double)x, (double)y, *fractol);
	if (fractol->mandelbrot == 1)
		iter = do_iterate(z, z, MAX_ITER, BOUND);
	else
		iter = do_iterate(z, fractol->c, MAX_ITER, BOUND);
	color = fractol->colors[iter % MAX_COLORS].color * (iter != MAX_ITER);
	ft_pixel_put(x, y, &(fractol->pixels), color);
}

void	render_fractol(t_fractal *fractol)
{
	int		x;
	int		y;
	char	*string;

	string = malloc(16);
	y = -1;
	while (++y < HEI)
	{
		x = -1;
		while (++x < WID)
		{
			get_pixel_color(x, y, fractol);
		}
	}
	mlx_put_image_to_window(fractol->connect, fractol->window, \
							fractol->image, 0, 0);
	free(string);
}
