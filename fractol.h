#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "minilibx-linux/mlx.h"
# include "X11/X.h"
# include "X11/keysym.h"
# define BLACK	0
# define MAGENTA 	120*255*255 + 50 *255 + 0
# define BLUE 		0  *255*255 + 150*255 + 45
# define ORANGE 	40 *255*255 + 0  *255 + 6
# define YELLOW 	50 *255*255 + 255*255 + 250
# define COLOR_MAX 	255*255*255 + 255*255 + 255

# define HEI 500
# define WID 800
# define MAX_ITER 424
# define BOUND 2

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

typedef struct	s_fractal
{
	void	*connect;
	void	*window;
	void	*image;
	t_pixels	pixels;
}				t_fractal;

#endif