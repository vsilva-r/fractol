#include "fractol.h"

int calculate_mandelbrot(double real, double im, t_fractal *fractal)
{
    t_complex   z;
    t_complex   c;
    int         i;
    z.real = 0.0;
    z.im = 0.0;
    c.real = real;
    c.im = im;
    i = 0;
    while (i < fractal->iterations)
    {
        z = sum(square(z), c);
        if ((z.real * z.real + z.im * z.im) > fractal->escape)
            return (i);
        i++;
    }
    return (fractal->iterations);
}

void my_pixel_put(int x, int y, t_image *img, int color)
{
    int result;
    result = (y * img->line_len) + (x * (img->bpp / 8));
    *(unsigned int *)(img->pixels + result) = color;
}

void handle_pixel(int x, int y, t_fractal *fractal)
{
    double  real;
    double  im;
    int     i;
    int     color;
    real = scale(x, fractal->min, fractal->max, WIDTH) * fractal->zoom + fractal->shift_x;
    im = scale(y, fractal->max, fractal->min, HEIGHT) * fractal->zoom + fractal->shift_y;
    color = 0;
    i = 0;
    if (fractal->type == 0)
        i = calculate_mandelbrot(real, im, fractal);
    else if (fractal->type == 1)
        i = calculate_julia(real, im, fractal);
    else if (fractal->type == 2)
        i = calculate_burning_ship(real, im, fractal);
    if (i == fractal->iterations)
        color = BLACK;
    else
        color = palette_1(i, fractal);
    my_pixel_put(x, y, &fractal->image, color);
}