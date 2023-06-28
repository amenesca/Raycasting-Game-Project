#include "../../includes/cub3d.h"

void    ft_mlx_pixel_put(t_data *data, int x, int y, int pixel)
{
    char    *dest;

	if (y >= h || x >= w || y < 0 || x < 0)
        return ;
    dest = data->mlxdata.addr + (y * data->mlxdata.line)\
	 + (x * (data->mlxdata.bits / 8));
    *(unsigned int *)dest = pixel;
}

void verline(t_data *data, int x, int start, int end, int color)
{
    int i;

    i = start;
    while (i <= end)
    {
    	ft_mlx_pixel_put(data, x, i, color);
        i++;
    }
}

void raycasting_no_textures(t_data *data)
{
	int x;
	int color = 0;

	x = -1;
	while (++x < w)
	{
		data->ray.cameraX = 2 * x / (double)w - 1;
		data->ray.rayX = data->ray.dir[0] + data->ray.plane[0] * data->ray.cameraX;
		data->ray.rayY = data->ray.dir[1] + data->ray.plane[1] * data->ray.cameraX;
		data->ray.mapX = (int)data->ray.playerpos[0];
		data->ray.mapY = (int)data->ray.playerpos[1];

		if (data->ray.rayX < EPSILON)
			data->ray.deltaX = 1e30;
		else
			data->ray.deltaX = fabs(1 / data->ray.rayX);

		if (data->ray.rayY < EPSILON)
			data->ray.deltaY = 1e30;
		else
			data->ray.deltaY = fabs(1 / data->ray.rayY);
		

		if (data->ray.rayX < 0)
		{
			data->ray.stepX = -1;
			data->ray.sideX = (data->ray.playerpos[0] - data->ray.mapX) * data->ray.deltaX;
		}
		else
		{
			data->ray.stepX = 1;
			data->ray.sideX = (data->ray.mapX + 1.0 - data->ray.playerpos[0]) * data->ray.deltaX;
		}
		if (data->ray.rayY < 0)
		{
			data->ray.stepY = -1;
			data->ray.sideY = (data->ray.playerpos[1] - data->ray.mapY) * data->ray.deltaY;
		}
		else
		{
			data->ray.stepY = 1;
			data->ray.sideY = (data->ray.mapY + 1.0 - data->ray.playerpos[1]) * data->ray.deltaY;
		}

		data->ray.hit = 0;
		while (data->ray.hit == 0)
		{
			if (data->ray.sideX < data->ray.sideY)
			{
				data->ray.sideX += data->ray.deltaX;
				data->ray.mapX += data->ray.stepX;
				data->ray.side = 0;
			}
			else
			{
				data->ray.sideY += data->ray.deltaY;
				data->ray.mapY += data->ray.stepY;
				data->ray.side = 1;
			}
			if (data->map.map[data->ray.mapX][data->ray.mapY] != '0')
				data->ray.hit = 1;
		}

		if (data->ray.side == 0)
			data->ray.perp_wall = (data->ray.sideX - data->ray.deltaX);
		else
			data->ray.perp_wall = (data->ray.sideY - data->ray.deltaY);
		
		data->ray.lineHeight = (int)(h / data->ray.perp_wall);
		
		data->ray.drawStart = -data->ray.lineHeight / 2 + h / 2;
		if (data->ray.drawStart < 0)
			data->ray.drawStart = 0;
		data->ray.drawEnd = data->ray.lineHeight / 2 + h / 2;
		if (data->ray.drawEnd >= h)
			data->ray.drawEnd = h - 1;

        color = 0xFF0000;
   
		if (data->ray.side == 1)
			color = color / 2;

		verline(data, x, data->ray.drawStart, data->ray.drawEnd, color);
	}
	mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.mlx_win, data->mlxdata.img, 0, 0);
}