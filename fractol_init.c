#include "fractol.h"

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
    fractal->color_base = 0x001000;
    fractal->mandelbrot = fractal->mandelbrot & 1;
    fractal->zoom = 1;
    fractal->translate = (t_complex){0, 0};
    fractal->moving = 0;
}

int     fractal_init(t_fractal *fractol)
{
    fractal_stats_init(fractol);
    return(fractal_mlx_init(fractol));
}

void    hooks_init(t_fractal *f)
{
    mlx_key_hook(f->window,
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
