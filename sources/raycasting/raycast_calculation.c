/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_calculation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femarque <femarque@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:27:31 by femarque          #+#    #+#             */
/*   Updated: 2023/07/05 15:06:07 by femarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calculate1(t_ray *ray, int x)
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

void	calculate2(t_ray *ray)
{
	if (ray->rayX < 0)
	{
		ray->stepX = -1;
		ray->sideX = (ray->playerpos[0] \
		- ray->mapX) * ray->deltaX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideX = (ray->mapX + 1.0 \
		- ray->playerpos[0]) * ray->deltaX;
	}
	if (ray->rayY < 0)
	{
		ray->stepY = -1;
		ray->sideY = (ray->playerpos[1] \
		- ray->mapY) * ray->deltaY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideY = (ray->mapY + 1.0 \
		- ray->playerpos[1]) * ray->deltaY;
	}
}

void	calculate3(t_ray *ray, t_map *map)
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

void	calculate4(t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall = (ray->sideX - ray->deltaX);
	else
		ray->perp_wall = (ray->sideY - ray->deltaY);
	ray->line_height = (int)(screenHeight / ray->perp_wall);
	ray->draw_start = -ray->line_height / 2 + screenHeight / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + screenHeight / 2;
	if (ray->draw_end >= screenHeight)
		ray->draw_end = screenHeight - 1;
}
