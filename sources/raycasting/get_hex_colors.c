#include "../../includes/cub3d.h"

int rgb_to_hex(int red, int green, int blue)
{
	int color;
	color = (red << 16) | (green << 8) | blue;
    
    return color;
}

void get_hex_colors(t_data *data)
{
	data->ray.ceil_color = rgb_to_hex(data->map.ceiling[0], data->map.ceiling[1], data->map.ceiling[2]);
	data->ray.floor_color = rgb_to_hex(data->map.floor[0], data->map.floor[1], data->map.floor[2]);
}

void put_ceil_floor(t_data *data)
{
	int x;
	int y;

	y = -1;
	while (++y < screenHeight)
	{
		x = -1;
		while (++x < screenWidth)
		{
			if (y < screenHeight / 2)
				ft_mlx_pixel_put(data, x, y, data->ray.ceil_color);
			else
				ft_mlx_pixel_put(data, x, y, data->ray.floor_color);
		}
	}
}