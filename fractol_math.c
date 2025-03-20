#include "fractol.h"

t_complex compute(t_complex z, t_complex c)
{
    t_complex   result;

    result.x = (z.x * z.x) - (z.y * z.y) + c.x;
    result.y = 2 * z.x * z.y + c.y;
    return(result);
}

double  magnitude(t_complex z)
{
    double abs;

    abs = sqrt((z.x * z.x) + (z.y * z.y));
    return abs;
}
/*
int     color_fade(void)
{
    static int  color;
    static int  flag_red;
    static int  flag_blue;
    static int  flag_green;

    if(color / RED == 255)
    {
        if(flag_green)
            color -= BLUE;
        if(flag_blue)
            color -= GREEN;
        else
            color += BLUE;
    }
    return(color);
}
*/