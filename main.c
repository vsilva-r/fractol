#include "fractol.h"
#include <math.h>

/* void	events_init(t_fractol *f)
{
	mlx_hook(f->mlx_window,
		KeyPress,
		KeyPressMask,
		key_handler,
		f);
	mlx_hook(f->mlx_window,
		ButtonPress,
		ButtonPressMask,
		mouse_handler,
		f);
	mlx_hook(f->mlx_window,
		DestroyNotify,
		StructureNotifyMask,
		close_handler,
		f);
} */

int    fractal_init(t_fractal *frac)
{
    frac->connect = mlx_init();
    if (!frac->connect)
        return(-1);
	frac->window = mlx_new_window(frac->connect, WID, HEI, "Hello world!");
	if (!frac->window) // free later
        mlx_destroy_display(frac->connect);
		free (frac->connect);
        return(-1);
    frac->image.img = mlx_new_image(frac->connect, WID, HEI);
	frac->image.addr = mlx_get_data_addr(frac->image.img, &frac->image.bpp, &frac->image.line_length,
								&frac->image.endian);
    return(0);
}

int	close_window(void *mlx, void *win, t_fractal *frac)
{
    printf("1 Closing window. Bye!");
	mlx_destroy_image(frac->connect, frac->image.img);
	mlx_destroy_window(frac->connect, win);
	mlx_destroy_display(frac->connect);
	free(frac->connect);
	exit(1);
    printf("2 Closing window. Bye!");
	return (-1);
}

void    hooks_init(t_fractal *f)
{
    mlx_hook(f->window,
		KeyPress,
		KeyPressMask,
		close_window,
		f);
	mlx_hook(f->window,
		ButtonPress,
		ButtonPressMask,
		close_window,
		f);
	mlx_hook(f->window,
		DestroyNotify,
		StructureNotifyMask,
		close_window,
		f);
}

// LEARN HOW THIS WORKS
void	ft_pixel_put(int x, int y, t_data *img, int color)
{
	int	offset;

	offset = (y * img->line_length) + (x * (img->bpp / 8));
	*(unsigned int *)(img->addr + offset) = color;
}

t_complex compute(t_complex z, t_complex c)
{
    t_complex   result;

    result.x = (z.x * z.x) - (z.y * z.y) + c.x;
    result.y = 2 * z.x * z.y + c.y;
    return(result);
}

double  magnitude(t_complex z)
{
    double abs;

    abs = sqrt((z.x * z.x) + (z.y * z.y));
    return abs;
}

int    do_iterate(t_complex z, t_complex c, int max_iter, double bound)
{
    int iter = -1;
    while(++iter < max_iter)
    {
        z = compute(z, c);
        if(magnitude(z) > bound)
            break ;
    }

    return  iter;
}

t_complex   get_complex(double x, double y, t_data img)
{
    t_complex   z;

    z.x = -BOUND + (x / WID) * 2 * BOUND;
    z.y = BOUND - (y / HEI) * 2 * BOUND;
    return(z);
}

void    get_pixel_color(int x, int y, t_complex c, t_data *img)
{
    t_complex   z;
    int         iter;
    int         color = x + y;

    z = get_complex((double)x, (double)y, *img);
    iter = do_iterate((t_complex){0, 0}, z, MAX_ITER, BOUND);
    color = rand() % 0x120045;
    /* color = COLOR_MAX / MAX_ITER * (iter % MAX_ITER); */
    ft_pixel_put(x, y, img, color);
}

int	main(int argc, char **argv)
{
	t_fractal   *fractol;
    t_data    img;
    int     y;
    int     x;
    t_complex   c;

    c.x = 0;
    c.y = 0;
    fractal_init(fractol);
    hooks_init(fractol);
	/* mlx = mlx_init();
    if (!mlx)
        return(-1);
	mlx_win = mlx_new_window(mlx, WID, HEI, "Hello world!");
	if (!mlx_win) // free later
        return(-1);
    mlx_hook(mlx_win,
		DestroyNotify,
		StructureNotifyMask,
		close_window,
		&mlx_win);
    mlx_hook(mlx_win,
		KeyPress,
		KeyPressMask,
		close_window,
		&mlx_win);
    img.img = mlx_new_image(mlx, WID, HEI);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length,
								&img.endian); */
    y = -1;
    while (++y < HEI)
    {
        x = -1;
        while (++x < WID)
        {
            /* ft_pixel_put(x, y, &img, (x-y)%1); */
            get_pixel_color(x, y, c, &img);
        }
    }
    mlx_put_image_to_window(fractol->connect, fractol->window, img.img, 0, 0);
    mlx_loop(fractol->connect);
    mlx_destroy_window(fractol->connect, fractol->window);
	mlx_destroy_display(fractol->connect);
	free(fractol->connect);
    return(0);
}

/* Apparently there are leaks to solve! Just use events later */