#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <time.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "X11/X.h"
# include "X11/keysym.h"
# define BLACK	0
# define WHITE 	0xffffff
# define RED 0x010000
# define GREEN 0x000100
# define BLUE 0x000001


# define HEI 720
# define WID 720
# define MAX_ITER 50
# define MAX_COLORS 52
# define BOUND 3

typedef	struct s_complex
{
	double	x;
	double	y;
}				t_complex;


typedef struct	s_pixels
{
	char	*ptr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_pixels;

typedef struct s_colorfade
{
	int	color;
	int	fade;
	int	direction;
}				t_colorfade;

typedef struct	s_fractal
{
	void	*connect;
	void	*window;
	void	*image;
	t_colorfade	colors[MAX_COLORS];
	int		mandelbrot;
	double	zoom;
	int		moving;
	t_complex	translate;
	t_complex	c;
	t_pixels	pixels;
}				t_fractal;

double	ft_atof(char *str);
int    fractal_init(t_fractal *fractal);
void    fractal_stats_init(t_fractal *fractal);
void    hooks_init(t_fractal *f);
t_colorfade	colorfade_r(t_colorfade colorfade);
t_colorfade	colorfade_l(t_colorfade colorfade);
void	fractal_fade_r(t_fractal *f);
void	fractal_fade_l(t_fractal *f);
t_complex   get_complex(double x, double y, t_fractal f);
t_complex compute(t_complex z, t_complex c);
double  magnitude(t_complex z);
int    do_iterate(t_complex z, t_complex c, int max_iter, double bound);
void    get_pixel_color(int x, int y, t_fractal *fractol);
void	ft_pixel_put(int x, int y, t_pixels *img, int color);
void    render_fractol(t_fractal *fractol);
int		handle_no_event(t_fractal *fractol);
int		mouse_handler(int keysym, int x, int y, t_fractal *fractal);
int		key_handler(int keysym, t_fractal *fractal);
int		close_window(t_fractal *fractal);

#endif