/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsilva-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:42:54 by vsilva-r          #+#    #+#             */
/*   Updated: 2025/05/23 13:42:57 by vsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_fractal	fractol;

	if (argc == 2 && !(ft_strncmp(argv[1], "mandelbrot", 10)))
		fractol.mandelbrot = 1;
	else if (argc == 3)
	{
		fractol.mandelbrot = 0;
		fractol.c_input.x = ft_atof(argv[1]);
		fractol.c_input.y = ft_atof(argv[2]);
	}
	else
	{
		ft_printf("Bad function call!\n");
		ft_printf("Usage:	%s mandelbrot\n", argv[0]);
		ft_printf("OR	%s num1 num2\n", argv[0]);
		exit(1);
	}
	fractal_init(&fractol);
	hooks_init(&fractol);
	render_fractol(&fractol);
	mlx_loop(fractol.connect);
	close_window(&fractol);
	return (0);
}

/* Apparently there are leaks to solve! Just use events later */
