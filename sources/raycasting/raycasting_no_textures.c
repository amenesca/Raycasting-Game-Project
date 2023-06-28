#include "../../includes/cub3d.h"

#define EPSILON 1e-6

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
		data->ray.rayDirX = data->ray.dir[0] + data->ray.plane[0] * data->ray.cameraX;
		data->ray.rayDirY = data->ray.dir[1] + data->ray.plane[1] * data->ray.cameraX;
		data->ray.mapX = (int)data->ray.playerpos[0];
		data->ray.mapY = (int)data->ray.playerpos[1];

		if (data->ray.rayDirX < EPSILON)
			data->ray.deltaDistX = 1e30;
		else
			data->ray.deltaDistX = fabs(1 / data->ray.rayDirX);

		if (data->ray.rayDirY < EPSILON)
			data->ray.deltaDistY = 1e30;
		else
			data->ray.deltaDistY = fabs(1 / data->ray.rayDirY);
		

		if (data->ray.rayDirX < 0)
		{
			data->ray.stepX = -1;
			data->ray.sideDistX = (data->ray.playerpos[0] - data->ray.mapX) * data->ray.deltaDistX;
		}
		else
		{
			data->ray.stepX = 1;
			data->ray.sideDistX = (data->ray.mapX + 1.0 - data->ray.playerpos[0]) * data->ray.deltaDistX;
		}
		if (data->ray.rayDirY < 0)
		{
			data->ray.stepY = -1;
			data->ray.sideDistY = (data->ray.playerpos[1] - data->ray.mapY) * data->ray.deltaDistY;
		}
		else
		{
			data->ray.stepY = 1;
			data->ray.sideDistY = (data->ray.mapY + 1.0 - data->ray.playerpos[1]) * data->ray.deltaDistY;
		}

		data->ray.hit = 0;
		while (data->ray.hit == 0)
		{
			if (data->ray.sideDistX < data->ray.sideDistY)
			{
				data->ray.sideDistX += data->ray.deltaDistX;
				data->ray.mapX += data->ray.stepX;
				data->ray.side = 0;
			}
			else
			{
				data->ray.sideDistY += data->ray.deltaDistY;
				data->ray.mapY += data->ray.stepY;
				data->ray.side = 1;
			}
			if (data->map.map[data->ray.mapX][data->ray.mapY] != '0')
				data->ray.hit = 1;
		}

		if (data->ray.side == 0)
			data->ray.perpWallDist = (data->ray.sideDistX - data->ray.deltaDistX);
		else
			data->ray.perpWallDist = (data->ray.sideDistY - data->ray.deltaDistY);
		
		data->ray.lineHeight = (int)(h / data->ray.perpWallDist);
		
		data->ray.drawStart = -data->ray.lineHeight / 2 + h / 2;
		if (data->ray.drawStart < 0)
			data->ray.drawStart = 0;
		data->ray.drawEnd = data->ray.lineHeight / 2 + h / 2;
		if (data->ray.drawEnd >= h)
			data->ray.drawEnd = h - 1;

		switch(data->map.map[data->ray.mapX][data->ray.mapY])
      {
        case 1:  color = 0x6A5ACD;  break; //red
        case 2:  color = 0x008080;  break; //green
        case 3:  color = 0x3CB371;   break; //blue
        case 4:  color = 0xADD8E6;  break; //white
        default: color = 0x4682B4; break; //yellow
      }
		if (data->ray.side == 1)
			color = color / 2;

		verline(data, x, data->ray.drawStart, data->ray.drawEnd, color);
	}
	mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.mlx_win, data->mlxdata.img, 0, 0);
}