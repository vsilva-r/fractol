#include "fractol.h"
#include <math.h>
#define HEI 500
#define WID 800
#define MAX_ITER 424
#define BOUND 2

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

    result.x = pow(z.x, 2) - pow(z.y, 2) + c.x;
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
    int iter;
    while(iter <= max_iter)
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
    int         color;

    z = get_complex((double)x, (double)y, *img);
    iter = do_iterate(z, c, MAX_ITER, BOUND);
    color = COLOR_MAX / MAX_ITER * (iter % MAX_ITER);
    ft_pixel_put(x, y, img, color);
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
    t_data    img;
    int     y;
    int     x;
    t_complex   c;

    c.x = 0;
    c.y = 0;
	mlx = mlx_init();
    if (!mlx)
        return(-1);
	mlx_win = mlx_new_window(mlx, WID, HEI, "Hello world!");
	if (!mlx_win) // free later
        return(-1);
    img.img = mlx_new_image(mlx, WID, HEI);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length,
								&img.endian);
    y = -1;
    while (++y < HEI)
    {
        x = -1;
        while (++x < WID)
        {
            get_pixel_color(x, y, c, &img);
        }
    }
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
    mlx_destroy_window(mlx, mlx_win);
	mlx_destroy_display(mlx);
	free(mlx);
    return(0);
}

/* Apparently there are leaks to solve!  */