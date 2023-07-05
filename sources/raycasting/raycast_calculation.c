/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_calculation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femarque <femarque@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:27:31 by femarque          #+#    #+#             */
/*   Updated: 2023/07/05 15:56:35 by femarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calculate1(t_ray *ray, int x)
{
	ray->camerax = 2 * x / (double)SCREEN_WIDTH - 1;
	ray->rayx = ray->dir[0] + ray->plane[0] * ray->camerax;
	ray->rayy = ray->dir[1] + ray->plane[1] * ray->camerax;
	ray->mapx = (int)ray->playerpos[0];
	ray->mapy = (int)ray->playerpos[1];
	if (ray->rayx == 0)
		ray->deltax = 1e30;
	else
		ray->deltax = fabs(1 / ray->rayx);
	if (ray->rayy == 0)
		ray->deltay = 1e30;
	else
		ray->deltay = fabs(1 / ray->rayy);
}

void	calculate2(t_ray *ray)
{
	if (ray->rayx < 0)
	{
		ray->stepx = -1;
		ray->sidex = (ray->playerpos[0] \
		- ray->mapx) * ray->deltax;
	}
	else
	{
		ray->stepx = 1;
		ray->sidex = (ray->mapx + 1.0 \
		- ray->playerpos[0]) * ray->deltax;
	}
	if (ray->rayy < 0)
	{
		ray->stepy = -1;
		ray->sidey = (ray->playerpos[1] \
		- ray->mapy) * ray->deltay;
	}
	else
	{
		ray->stepy = 1;
		ray->sidey = (ray->mapy + 1.0 \
		- ray->playerpos[1]) * ray->deltay;
	}
}

void	calculate3(t_ray *ray, t_map *map)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->sidex < ray->sidey)
		{
			ray->sidex += ray->deltax;
			ray->mapx += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->sidey += ray->deltay;
			ray->mapy += ray->stepy;
			ray->side = 1;
		}
		if (map->map[ray->mapx][ray->mapy] != '0')
			ray->hit = 1;
	}
}

void	calculate4(t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall = (ray->sidex - ray->deltax);
	else
		ray->perp_wall = (ray->sidey - ray->deltay);
	ray->line_height = (int)(SCREEN_HEIGHT / ray->perp_wall);
	ray->draw_start = -ray->line_height / 2 + SCREEN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + SCREEN_HEIGHT / 2;
	if (ray->draw_end >= SCREEN_HEIGHT)
		ray->draw_end = SCREEN_HEIGHT - 1;
}
