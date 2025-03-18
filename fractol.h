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

typedef	struct s_complex
{
	double	x;
	double	y;
}				t_complex;


typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_data;

#endif