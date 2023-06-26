/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femarque <femarque@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:08:05 by femarque          #+#    #+#             */
/*   Updated: 2023/06/25 16:27:55 by femarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void verLine(t_data *data, int x, int y1, int y2, int color)
{
    int i;
    for (i = y1; i <= y2; i++)
        mlx_pixel_put(data->mlxdata.mlx, data->mlxdata.mlx_win, x, i, color);
}

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

void config_ray(t_data *data, int x)
{
	t_ray ray;

	ray = data->ray;
	ray.cameraX = 2 * x / w - 1;
	ray.rayX = ray.dir[0] + ray.plane[0] * ray.cameraX;
	ray.rayY = ray.dir[1] + ray.plane[1] * ray.cameraX;
	ray.mapX = (int)ray.playerpos[0];
	ray.mapY = (int)ray.playerpos[1];
	if (ray.rayX == 0)
		ray.rayX = 1e30;
	else
		ray.deltaX = fabs(1 / ray.rayX);
	if (ray.rayY == 0)
		ray.rayY = 1e30;
	else
		ray.deltaY = fabs(1 / ray.rayY);
	ray.hit = 0;
}

void	side_step(t_data *data)
{
	t_ray ray;

	ray = data->ray;
	if (ray.rayX < 0)
	{
		ray.stepX = -1;
		ray.sideX = (ray.playerpos[0] - ray.mapX) * ray.deltaX;
	}
	else
	{
		ray.stepX = 1;
		ray.sideX = (ray.mapX + 1.0 - ray.playerpos[0]) * ray.deltaX;
	}
	if (ray.rayY < 0)
	{
		ray.stepY = -1;
		ray.sideY = (ray.playerpos[1] - ray.mapY) * ray.deltaY;
	}
	else
	{
		ray.stepY = 1;
		ray.sideY = (ray.mapY + 1.0 - ray.playerpos[1]) * ray.deltaY;
	}
}

void camera_man(t_data *data)
{
	t_ray ray;

	ray = data->ray;
	if(ray.side == 0)
		ray.perp_wall = (ray.sideX - ray.deltaX);
	else
		ray.perp_wall = (ray.sideY - ray.deltaY);
}

void	dda(t_data *data)
{
	t_ray	ray;

	ray = data->ray;
	while (ray.hit == 0)
	{
		if (ray.sideX < ray.sideY)
		{
			ray.sideX += ray.deltaX;
			ray.mapX += ray.stepX;
			ray.side = 0;
		}
		else
		{
			ray.sideY += ray.deltaY;
			ray.mapY += ray.stepY;
			ray.side = 1;
		}
		if (ray.mapX >= 0 && ray.mapX < data->map.map_width &&\
		 ray.mapY >= 0 && ray.mapY < data->map.map_height)
		{
			if(data->map.map[ray.mapX][ray.mapY] != '0')
				ray.hit = 1;
		}
		else
			ft_error("ERROR: Index outside of matrix limits");
	}
}

void	ray_line(t_data *data)
{
	t_ray	ray;

	ray = data->ray;
	ray.lineHeight = (int)(h / ray.perp_wall);
	ray.drawStart = (-1 * ray.lineHeight) / 2 + h / 2;
	if(ray.drawStart < 0)
		ray.drawStart = 0;
	ray.drawEnd = ray.lineHeight / 2 + h / 2;
	if(ray.drawEnd >= h)
		ray.drawEnd = h - 1;
}

void	ray_color(t_data *data, int x)
{
	t_ray	ray;

	ray = data->ray;
	int color;
	if (data->map.map[ray.mapX][ray.mapY] == '1')
		color = 0xFF0000; // red
	else if (data->map.map[ray.mapX][ray.mapY] == '2')
		color = 0x00FF00; // green
	else if (data->map.map[ray.mapX][ray.mapY] == '3')
		color = 0x0000FF; // blue
	else if (data->map.map[ray.mapX][ray.mapY] == '4')
		color = 0xFFFFFF; // white
	else
		color = 0xFFFF00; // yellow
	if (ray.side == 1)
		color = divideColorByValue(color, 2);
	verLine(data, x, ray.drawStart, ray.drawEnd, color);
}

void render(t_data *data)
{
	int x;
	
	x = 0;
    while (x < w)
    {
		config_ray(data, x);
		side_step(data);
		dda(data);
		camera_man(data);
		ray_line(data);
		ray_color(data, x);
		x++;
	}
}

int game(t_data *data)
{
	render(data);
	return (0);
}
