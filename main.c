#include "fractol.h"
#define HEI 1080
#define WID 1920


void	ft_pixel_put(int x, int y, t_data *img, int color)
{
	int	offset;

	offset = (y * img->line_length) + (x * (img->bpp / 8));
	*(unsigned int *)(img->addr + offset) = color;
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
    t_data    img;
    int     y;
    int     x;
    int     color = 91*255 + 0;

	mlx = mlx_init();
    if (!mlx)
        return(-1);
	mlx_win = mlx_new_window(mlx, WID, HEI, "Hello world!");
	if (!mlx_win) // free later
        return(-1);
    img.img = mlx_new_image(mlx, WID, HEI);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length,
								&img.endian);
    y = -1;
    while (++y < HEI)
    {
        x = -1;
        while (++x < WID)
        {
            ft_pixel_put(x, y, &img, color);
        }
        if(y == HEI / 2)
            color = 255*255*255 + 213*255 + 0;
    }
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
    mlx_destroy_window(mlx, mlx_win);
	mlx_destroy_display(mlx);
	free(mlx);
    return(0);
}