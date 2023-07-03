#include "../../includes/cub3d.h"

int divideColorByValue(int color, int value)
{
    int red = (color & 0xFF0000) >> 16;
    int green = (color & 0x00FF00) >> 8;
    int blue = color & 0x0000FF;

    red /= value;
    green /= value;
    blue /= value;

    return (red << 16) | (green << 8) | blue;
}

void    ft_mlx_pixel_put(t_data *data, int x, int y, int pixel)
{
    char    *dest;

	if (y >= screenHeight || x >= screenWidth || y < 0 || x < 0)
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

void calculate1(t_ray *ray, int x)
{
	ray->cameraX = 2 * x / (double)screenWidth - 1;
	ray->rayX = ray->dir[0] + ray->plane[0] * ray->cameraX;
	ray->rayY = ray->dir[1] + ray->plane[1] * ray->cameraX;
	ray->mapX = (int)ray->playerpos[0];
	ray->mapY = (int)ray->playerpos[1];
	if (ray->rayX == 0)
		ray->deltaX = 1e30;
	else
		ray->deltaX = fabs(1 / ray->rayX);
	if (ray->rayY == 0)
		ray->deltaY = 1e30;
	else
		ray->deltaY = fabs(1 / ray->rayY);
}

void calculate2(t_ray *ray)
{
	if (ray->rayX < 0)
	{
		ray->stepX = -1;
		ray->sideX = (ray->playerpos[0]\
		 - ray->mapX) * ray->deltaX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideX = (ray->mapX + 1.0\
		 - ray->playerpos[0]) * ray->deltaX;
	}
	if (ray->rayY < 0)
	{
		ray->stepY = -1;
		ray->sideY = (ray->playerpos[1]\
		 - ray->mapY) * ray->deltaY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideY = (ray->mapY + 1.0\
		 - ray->playerpos[1]) * ray->deltaY;
	}
}

void calculate3(t_ray *ray, t_map *map)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->sideX < ray->sideY)
		{
			ray->sideX += ray->deltaX;
			ray->mapX += ray->stepX;
			ray->side = 0;
		}
		else
		{
			ray->sideY += ray->deltaY;
			ray->mapY += ray->stepY;
			ray->side = 1;
		}
		if (map->map[ray->mapX][ray->mapY] != '0')
			ray->hit = 1;
	}
}

void calculate4(t_data *data, t_ray *ray, int x)
{
	int color;

	if (ray->side == 0)
		ray->perp_wall = (ray->sideX - ray->deltaX);
	else
		ray->perp_wall = (ray->sideY - ray->deltaY);
	
	ray->lineHeight = (int)(screenHeight / ray->perp_wall);
	
	ray->drawStart = -ray->lineHeight / 2 + screenHeight / 2;
	if (ray->drawStart < 0)
		ray->drawStart = 0;
	ray->drawEnd = ray->lineHeight / 2 + screenHeight / 2;
	if (ray->drawEnd >= screenHeight)
		ray->drawEnd = screenHeight - 1;

	color = 0xFF2599;

	if (ray->side == 1)
		color = divideColorByValue(color, 2);

	verline(data, x, ray->drawStart,\
	 ray->drawEnd, color);
}

void	tex_x_coordinate(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
		ray->wallX = ray->playerpos[1] + ray->perp_wall * ray->dir[1];
	else
		ray->wallX = ray->playerpos[0] + ray->perp_wall * ray->dir[0];
	ray->wallX -= floor(ray->wallX);

	ray->texX = (int)(ray->wallX * (double)(data->mlxdata.text_N.tex_width));
	if (ray->side == 0 && ray->dir[0] > 0)
		ray->texX = data->mlxdata.text_N.tex_width - ray->texX - 1;
	if (ray->side == 1 && ray->dir[1] < 0)
		ray->texX = data->mlxdata.text_N.tex_width - ray->texX - 1;
}

void tex_color(t_ray *ray, t_mlxdata *mlxdata)
{
	// how much to increase the texture coordinate per screen pixel
	ray->scale = 1.0 * mlxdata->text_N.tex_height\
	 / ray->lineHeight;
	// starting texture coordinate
	ray->texPos = (ray->drawStart - screenHeight\
	 / 2 + ray->lineHeight / 2) * ray->scale;
}

void raycaster(t_data *data)
{
	int x;

	x = -1;
	put_ceil_floor(data);
	while (++x < screenWidth)
	{
		calculate1(&data->ray, x);
		calculate2(&data->ray);
		calculate3(&data->ray, &data->map);
		calculate4(data, &data->ray, x);
//		tex_x_coordinate(data, &data->ray);
//		tex_color(&data->ray, &data->mlxdata);

	}
	mlx_put_image_to_window(data->mlxdata.mlx, \
	data->mlxdata.mlx_win, data->mlxdata.img, 0, 0);
}

int game(t_data *data)
{
	if (data->ray.flag == 1)
	{
		raycaster(data);
		data->ray.flag = 0;
	}
	return (0);
}