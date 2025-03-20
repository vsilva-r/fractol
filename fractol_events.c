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
    fractol->c.x += flag * (double)2 * (double)BOUND / (double)WID * 5;
    render_fractol(fractol);
    return(0);
}

int mouse_handler(int keysym, int x, int y, t_fractal *fractal)
{
    (void)keysym;
    (void)x;
    (void)y;
    printf("Mouse Closing window. Bye!");
	mlx_destroy_image(fractal->connect, fractal->image);
	mlx_destroy_window(fractal->connect, fractal->window);
	mlx_destroy_display(fractal->connect);
	free(fractal->connect);
	exit(1);
    printf("2 Closing window. Bye!");
	return (-1);
}

int key_handler(int keysym, t_fractal *fractal)
{
    if(keysym == XK_0)
    {
        fractal->color_base += 0xff00ff;
        render_fractol(fractal);
    }
    if(keysym == XK_9)
    {
        fractal->color_base -= 0xff00ff;
        render_fractol(fractal);
    }
    if(keysym == XK_Escape)
    {
        printf("Key Closing window. Bye!");
        mlx_destroy_image(fractal->connect, fractal->image);
        mlx_destroy_window(fractal->connect, fractal->window);
        mlx_destroy_display(fractal->connect);
        free(fractal->connect);
        exit(1);
        printf("2 Closing window. Bye!");       
    }
    return (-1);
    
}

int	close_window(t_fractal *fractal)
{
    printf("Other Closing window. Bye!");
	mlx_destroy_image(fractal->connect, fractal->image);
	mlx_destroy_window(fractal->connect, fractal->window);
	mlx_destroy_display(fractal->connect);
	free(fractal->connect);
	exit(1);
    printf("2 Closing window. Bye!");
	return (-1);
}
