/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femarque <femarque@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:12:21 by femarque          #+#    #+#             */
/*   Updated: 2023/06/19 18:37:38 by femarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int init_data(t_data *data)
{
	data->mlxdata.bits = 0;
	data->mlxdata.line = 0;
	data->mlxdata.finish = 0;
	data->mlxdata.endian = 0;
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
	if (keycode == KEY_ESC)
		close_game(game);
	if (game->finish == 1)
		close_game(game);
	/*else
		deal_key(keycode, game);*/
	return (0);
}