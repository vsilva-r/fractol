#include "fractol.h"
#define COLORS_PHASE 0xffffff / MAX_COLORS

int    fractal_mlx_init(t_fractal *fractal)
{
    fractal->connect = mlx_init();
    if (!fractal->connect)
    {
        free(fractal->connect);
        return(-1);
    }
	fractal->window = mlx_new_window(fractal->connect, WID, HEI, "Fract'ol!");
	if (!fractal->window)
    {
        mlx_destroy_display(fractal->connect);
		free (fractal->connect);
        return(-1);
    }
    fractal->image = mlx_new_image(fractal->connect, WID, HEI);
	if (!fractal->image)
    {
        mlx_destroy_window(fractal->connect, fractal->window);
		mlx_destroy_display(fractal->connect);
		free (fractal->connect);
        return(-1);
    }
    fractal->pixels.ptr = mlx_get_data_addr(fractal->image, &fractal->pixels.bpp, &fractal->pixels.line_length,
								&fractal->pixels.endian);
    
    return(0);
}

void    fractal_stats_init(t_fractal *fractal)
{
    fractal->mandelbrot = fractal->mandelbrot & 1;
    fractal->zoom = 1;
    fractal->translate = (t_complex){0, 0};
    fractal->moving = 0;
}

void    fractal_colors_init(t_fractal *fractal)
{
    int i;
    int j;

    fractal->colors[0] = (t_colorfade){0xff0000, 1, -1};
    i = 0;
    while (++i < MAX_COLORS)
    {
        fractal->colors[i] = colorfade_r(fractal->colors[i-1]);
        j = 0;
        while (++j < COLORS_PHASE)
            fractal->colors[i] = colorfade_r(fractal->colors[i]);
    }
}

int     fractal_init(t_fractal *fractol)
{
    fractal_stats_init(fractol);
    fractal_colors_init(fractol);
    return(fractal_mlx_init(fractol));
}

void    hooks_init(t_fractal *f)
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
