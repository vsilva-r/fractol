#include "fractol.h"

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

int	main(int argc, char* argv[]) // int argc, char **argv)
{
	t_fractal   fractol;
    
    if (argc == 2 && !(ft_strncmp(argv[1], "mandelbrot", 10)))
    {
        fractol.mandelbrot = 1;
    }
    else if (argc == 3)
    {
        fractol.mandelbrot = 0;
        fractol.c.x = ft_atof(argv[1]);
        fractol.c.y = ft_atof(argv[2]);
    }
    else
    {
        printf("Bad function call!\n");
        printf("Usage:	%s mandelbrot\n", argv[0]);
        printf("OR	%s num1 num2\n", argv[0]);
        exit(1);
    }
    fractal_init(&fractol);
    hooks_init(&fractol);
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
    render_fractol(&fractol);
    mlx_loop(fractol.connect);
    mlx_destroy_image(fractol.connect, fractol.image);
    mlx_destroy_window(fractol.connect, fractol.window);
	mlx_destroy_display(fractol.connect);
	free(fractol.connect);
    return(0);
}

/* Apparently there are leaks to solve! Just use events later */