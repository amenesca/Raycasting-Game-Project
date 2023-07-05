/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femarque <femarque@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:12:21 by femarque          #+#    #+#             */
/*   Updated: 2023/07/05 13:21:35 by femarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	init_data(t_data *data)
{
	data->mlx.bits = 0;
	data->mlx.line = 0;
	data->mlx.finish = 0;
	data->mlx.endian = 0;
	data->ray.mapX = 0;
	data->ray.mapY = 0;
	data->ray.hit = 0;
	data->ray.side = 0;
	data->ray.stepX = 0;
	data->ray.stepY = 0;
	data->ray.sideX = 0;
	data->ray.sideY = 0;
	data->ray.rayX = 0;
	data->ray.rayY = 0;
	data->ray.deltaX = 0;
	data->ray.deltaY = 0;
	data->ray.perp_wall = 0;
	data->ray.line_height = 0;
	data->ray.draw_start = 0;
	data->ray.draw_end = 0;
	data->ray.move_v = 0;
	data->ray.move_h = 0;
	data->ray.turn = 0;
	init_mlx(data);
	return (0);
}

int	init_mlx(t_data *data)
{
	data->mlx.mlx = mlx_init();
	data->mlx.mlx_win = mlx_new_window(data->mlx.mlx, \
	screenWidth, screenHeight, "cub3d");
	data->mlx.img = mlx_new_image(data->mlx.mlx, screenWidth, screenHeight);
	data->mlx.addr = mlx_get_data_addr(data->mlx.img, \
	&data->mlx.bits, &data->mlx.line, &data->mlx.endian);
	ft_xpm_to_img(&data->mlx.text_N, &data->map, &data->mlx, 0);
	ft_xpm_to_img(&data->mlx.text_S, &data->map, &data->mlx, 1);
	ft_xpm_to_img(&data->mlx.text_W, &data->map, &data->mlx, 2);
	ft_xpm_to_img(&data->mlx.text_E, &data->map, &data->mlx, 3);
	return (0);
}

int	close_game(t_mlx *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	free(game->mlx);
	exit(0);
	return (0);
}
