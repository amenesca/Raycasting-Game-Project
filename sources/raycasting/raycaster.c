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

int    get_pixel_color(t_img *img, int x, int y)
{
    int        color;
    char    *dst;

    dst = img->addr + (y * img->line + x * (img->bits / 8));
    color = *(unsigned int *)dst;
    return (color);
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

void calculate4(t_ray *ray)
{
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
}

void	tex_x_coordinate(t_ray *ray)
{
	if (ray->side == 0)
		ray->wallX = ray->playerpos[1] + ray->perp_wall * ray->rayY;
	else
		ray->wallX = ray->playerpos[0] + ray->perp_wall * ray->rayX;
	ray->wallX -= floor(ray->wallX);

	ray->texX = (int)(ray->wallX * (double)(64.0));
	if (ray->side == 0 && ray->rayX > 0)
		ray->texX = 64 - ray->texX - 1;
	if (ray->side == 1 && ray->rayY < 0)
		ray->texX = 64 - ray->texX - 1;
}

void tex_color(t_data *data, int x)
{
	int y;
	int color;

	y = data->ray.drawStart;
	if (y >= screenHeight || x >= screenWidth || y < 0 || x < 0)
        return ;
	// how much to increase the texture coordinate per screen pixel
	data->ray.scale = 1.0 * (double)64 / data->ray.lineHeight;
	// starting texture coordinate
	data->ray.texPos = (data->ray.drawStart - screenHeight / 2 + data->ray.lineHeight / 2) * data->ray.scale;
	while (y < data->ray.drawEnd)
	{
		data->ray.texY = (int)data->ray.texPos & (64 - 1);
		data->ray.texPos += data->ray.scale;
		color = get_pixel_color(&data->mlxdata.text_N, data->ray.texX, data->ray.texY);
		ft_mlx_pixel_put(data, x, y, color);
		y++;
	}
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
		calculate4(&data->ray);
		tex_x_coordinate(&data->ray);
		tex_color(data, x);
	}
	mlx_put_image_to_window(data->mlxdata.mlx, \
	data->mlxdata.mlx_win, data->mlxdata.img, 0, 0);
}

int game(t_data *data)
{
	raycaster(data);
	movement_y(data);
	movement_x(data);
	mov_camera(data);
	return (0);
}