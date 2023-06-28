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

static void    ft_mlx_pixel_put(t_data *data, int x, int y, int pixel)
{
    char    *dest;

	if (y >= h || x >= w || y < 0 || x < 0)
        return ;
    dest = data->mlxdata.addr + (y * data->mlxdata.line)\
	 + (x * (data->mlxdata.bits / 8));
    *(unsigned int *)dest = pixel;
}

static void verline(t_data *data, int x, int start, int end, int color)
{
    int i;

    i = start;
    while (i <= end)
    {
    	ft_mlx_pixel_put(data, x, i, color);
        i++;
    }
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

void config_ray(t_ray *ray_pointer ,int x)
{
	ray_pointer->cameraX = 2 * x / w - 1;
	ray_pointer->rayX = ray_pointer->dir[0] + ray_pointer->plane[0] * ray_pointer->cameraX;
	ray_pointer->rayY = ray_pointer->dir[1] + ray_pointer->plane[1] * ray_pointer->cameraX;
	ray_pointer->mapX = (int)ray_pointer->playerpos[0];
	ray_pointer->mapY = (int)ray_pointer->playerpos[1];
	if (ray_pointer->rayX == 0)
		ray_pointer->rayX = 1e30;
	else
		ray_pointer->deltaX = fabs(1 / ray_pointer->rayX);
	if (ray_pointer->rayY == 0)
		ray_pointer->rayY = 1e30;
	else
		ray_pointer->deltaY = fabs(1 / ray_pointer->rayY);
}

void	side_step(t_ray *ray_pointer)
{
	if (ray_pointer->rayX < 0)
	{
		ray_pointer->stepX = -1;
		ray_pointer->sideX = (ray_pointer->playerpos[0] - ray_pointer->mapX) * ray_pointer->deltaX;
	}
	else
	{
		ray_pointer->stepX = 1;
		ray_pointer->sideX = (ray_pointer->mapX + 1.0 - ray_pointer->playerpos[0]) * ray_pointer->deltaX;
	}
	if (ray_pointer->rayY < 0)
	{
		ray_pointer->stepY = -1;
		ray_pointer->sideY = (ray_pointer->playerpos[1] - ray_pointer->mapY) * ray_pointer->deltaY;
	}
	else
	{
		ray_pointer->stepY = 1;
		ray_pointer->sideY = (ray_pointer->mapY + 1.0 - ray_pointer->playerpos[1]) * ray_pointer->deltaY;
	}
}

void camera_man(t_ray *ray_pointer)
{
	if(ray_pointer->side == 0)
		ray_pointer->perp_wall = (ray_pointer->sideX - ray_pointer->deltaX);
	else
		ray_pointer->perp_wall = (ray_pointer->sideY - ray_pointer->deltaY);
}

void	dda(t_data *data, t_ray *ray_pointer)
{
	ray_pointer->hit = 0;
	while (ray_pointer->hit == 0)
	{
		if (ray_pointer->sideX < ray_pointer->sideY)
		{
			ray_pointer->sideX += ray_pointer->deltaX;
			ray_pointer->mapX += ray_pointer->stepX;
			ray_pointer->side = 0;
		}
		else
		{
			ray_pointer->sideY += ray_pointer->deltaY;
			ray_pointer->mapY += ray_pointer->stepY;
			ray_pointer->side = 1;
		}
		if (ray_pointer->mapX >= 0 && ray_pointer->mapX < data->map.map_width &&\
		 ray_pointer->mapY >= 0 && ray_pointer->mapY < data->map.map_height)
		{
			if(data->map.map[ray_pointer->mapX][ray_pointer->mapY] != '0')
				ray_pointer->hit = 1;
		}
		else
			ft_error("ERROR: Index outside of matrix limits");
	}
}

void	ray_line(t_ray *ray_pointer)
{
	ray_pointer->lineHeight = (int)(h / ray_pointer->perp_wall);
	ray_pointer->drawStart = (-1 * ray_pointer->lineHeight) / 2 + h / 2;
	if(ray_pointer->drawStart < 0)
		ray_pointer->drawStart = 0;
	ray_pointer->drawEnd = ray_pointer->lineHeight / 2 + h / 2;
	if(ray_pointer->drawEnd >= h)
		ray_pointer->drawEnd = h - 1;
}

void	ray_color(t_data *data, t_ray *ray_pointer, int x)
{
	int color;

		color = 0xFFFF00; // yellow
	if (ray_pointer->side == 1)
		color = divideColorByValue(color, 2);
	verline(data, x, ray_pointer->drawStart, ray_pointer->drawEnd, color);
}

void render(t_data *data)
{
	int x;
	
	x = 0;
    while (x < w)
    {
		config_ray(&data->ray, x);
		side_step(&data->ray);
		dda(data, &data->ray);
		camera_man(&data->ray);
		ray_line(&data->ray);
		ray_color(data, &data->ray, x);
		x++;
	}
	mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.mlx_win, data->mlxdata.img, 0, 0);
}

int game(t_data *data)
{
	render(data);
	return (0);
}
