#include "fractol.h"

typedef struct s_fractal
{
    int     iterations;
    double  escape;
    int     max;

    
}; t_fractal


int calculate_mandelbrot(double real, double im, t_fractal *fractal);
void my_pixel_put(int x, int y, t_image *img, int color);
void handle_pixel(int x, int y, t_fractal *fractal);