/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femarque <femarque@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:12:21 by femarque          #+#    #+#             */
/*   Updated: 2023/06/24 18:57:49 by femarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int init_data(t_data *data)
{
	t_ray *ray;

	ray = data->ray;
	data->mlxdata.bits = 0;
	data->mlxdata.line = 0;
	data->mlxdata.finish = 0;
	data->mlxdata.endian = 0;
	ray->mapX = 0;
	ray->mapY = 0;
	ray->hit = 0;
	ray->side = 0;
	ray->stepX = 0;
	ray->stepY = 0;
	ray->sideX = 0;
	ray->sideY = 0;
	ray->rayX = 0;
	ray->rayY = 0;
	ray->deltaX = 0;
	ray->deltaY = 0;
	ray->perp_wall = 0;
	ray->lineHeight = 0;
	ray->drawStart = 0;
	ray->drawEnd = 0;
	init_mlx(data);
	return (0);
}

int init_mlx(t_data *data)
{
	data->mlxdata.mlx = mlx_init();
	data->mlxdata.mlx_win = mlx_new_window(data->mlxdata.mlx, w, h, "cub3d");
	return (0);
}

int	close_game(t_mlxdata *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	free(game->mlx);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_mlxdata *game)
{
	double moveSpeed = 0.1;
    double rotSpeed = 0.05;
	
	if (keycode == ESC_KEY)
		close_game(game);
	if (game->finish == 1)
		close_game(game);
	else
		deal_key(keycode, game, moveSpeed, rotSpeed);
	return (0);
}