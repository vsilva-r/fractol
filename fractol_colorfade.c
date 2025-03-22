#include "fractol.h"
#define R 3
#define G 2
#define B 1
#define FADE_DIGITS (colorfade.color & (colorfade.fade * 255)) / \
	colorfade.fade % 255
	
t_colorfade	colorfade_r(t_colorfade colorfade)
{
	if (FADE_DIGITS == 0)
	{
		colorfade.fade = (colorfade.fade << 8) % 0xffffff;
		colorfade.direction *= -1;
	}
	colorfade.color += colorfade.fade * colorfade.direction;
	return (colorfade);
}

t_colorfade	colorfade_l(t_colorfade colorfade)
{
	if (FADE_DIGITS == 0)
	{
		colorfade.fade = (colorfade.fade >> 8) % 0xffffff;
		if (colorfade.fade == 0)
			colorfade.fade = 0x010000;
		colorfade.direction *= -1;
	}
	colorfade.color -= colorfade.fade * colorfade.direction;
	return (colorfade);
}

void	fractal_fade_r(t_fractal *f)
{
	int	i;

	i = -1;
	while (++i < MAX_COLORS)
	{
		f->colors[i] = colorfade_r(f->colors[i]);
	}
}

void	fractal_fade_l(t_fractal *f)
{
	int	i;

	i = -1;
	while (++i < MAX_COLORS)
	{
		f->colors[i] = colorfade_l(f->colors[i]);
	}
}