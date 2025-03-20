#include "fractol.h"

int    handle_no_event(t_fractal *fractol)
{
    static int  flag;
    /* static time_t time;

    if( - time < )
         */
    (void)fractol;
    // fractol->color_base += 0x010101;
    flag = -1;
    if(magnitude(fractol->c) >= BOUND)
        flag *= 1;
    if (fractol->moving)
    {
         fractol->c.x += flag * (double)2 * (double)BOUND / (double)WID * 5;
    }
    render_fractol(fractol);
    return(0);
}

int mouse_handler(int keysym, int x, int y, t_fractal *fractal)
{
    // t_complex   mouse_pos;

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
    // mouse_pos = get_complex(x, y, fractal);
    //fractal->translate.x *= (x - BOUND / 2) / BOUND; //(x - WID / 2) / WID;
    //fractal->translate.y *= (y - BOUND / 2) / BOUND; //(y - HEI / 2) / HEI;
    render_fractol(fractal);
	return (-1);
}

int key_handler(int keysym, t_fractal *fractal)
{
    if (keysym == XK_R)
    {
        fractal_stats_init(fractal);
    }
    if (keysym == XK_space)
        fractal->moving ^= 1;
    if(keysym == XK_0)
    {
        fractal->color_base += 0xff00ff;
    }
    if(keysym == XK_9)
    {
        fractal->color_base -= 0xff00ff;
    }
    if (keysym == XK_M)
    {
        fractal->mandelbrot = 1;
    }
    if (keysym == XK_Left)
        fractal->translate.x += 0.1;
    if (keysym == XK_Right)
        fractal->translate.x -= 0.1;
    if (keysym == XK_Up)
        fractal->translate.y += 0.1;
    if (keysym == XK_Down)
        fractal->translate.y -= 0.1;
    if(keysym == XK_Escape)
    {
        printf("ESC pressed. \n");
        close_window(fractal);
    }
    render_fractol(fractal);
    return (-1);
    
}

int	close_window(t_fractal *fractal)
{
    printf("Closing window. Bye!\n");
	mlx_destroy_image(fractal->connect, fractal->image);
	mlx_destroy_window(fractal->connect, fractal->window);
	mlx_destroy_display(fractal->connect);
	free(fractal->connect);
	exit(1);
	return (-1);
}
