/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femarque <femarque@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:12:21 by femarque          #+#    #+#             */
/*   Updated: 2023/06/25 16:29:27 by femarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int init_data(t_data *data)
{
	data->mlxdata.bits = 0;
	data->mlxdata.line = 0;
	data->mlxdata.finish = 0;
	data->mlxdata.endian = 0;
	data->ray.mapX = 0;
	data->ray.mapY = 0;
	data->ray.hit = 0;
	data->ray.side = 0;
	data->ray.stepX = 0;
	data->ray.stepY = 0;
	data->ray.sideDistX = 0;
	data->ray.sideDistY = 0;
	data->ray.rayDirX = 0;
	data->ray.rayDirY = 0;
	data->ray.deltaDistX = 0;
	data->ray.deltaDistY = 0;
	data->ray.perpWallDist = 0;
	data->ray.lineHeight = 0;
	data->ray.drawStart = 0;
	data->ray.drawEnd = 0;
	init_mlx(data);
	return (0);
}

int init_mlx(t_data *data)
{
	data->mlxdata.mlx = mlx_init();
	data->mlxdata.mlx_win = mlx_new_window(data->mlxdata.mlx, w, h, "cub3d");
	data->mlxdata.img = mlx_new_image(data->mlxdata.mlx, w, h);
	data->mlxdata.addr = mlx_get_data_addr(data->mlxdata.img,\
	 &data->mlxdata.bits, &data->mlxdata.line, &data->mlxdata.endian);
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
	/*double moveSpeed = 0.1;
    double rotSpeed = 0.05;*/
	
	if (keycode == KEY_ESC)
		close_game(game);
	if (game->finish == 1)
		close_game(game);
	/*else
		deal_key(keycode, game, moveSpeed, rotSpeed);*/
	return (0);
}