/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femarque <femarque@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:12:21 by femarque          #+#    #+#             */
/*   Updated: 2023/07/05 15:56:35 by femarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	init_data(t_data *data)
{
	data->mlx.bits = 0;
	data->mlx.line = 0;
	data->mlx.finish = 0;
	data->mlx.endian = 0;
	data->ray.mapx = 0;
	data->ray.mapy = 0;
	data->ray.hit = 0;
	data->ray.side = 0;
	data->ray.stepx = 0;
	data->ray.stepy = 0;
	data->ray.sidex = 0;
	data->ray.sidey = 0;
	data->ray.rayx = 0;
	data->ray.rayy = 0;
	data->ray.deltax = 0;
	data->ray.deltay = 0;
	data->ray.perp_wall = 0;
	data->ray.line_height = 0;
	data->ray.draw_start = 0;
	data->ray.draw_end = 0;
	data->ray.move_v = 0;
	data->ray.move_h = 0;
	data->ray.turn = 0;
	data->mlx.finish = 0;
	init_mlx(data);
	return (0);
}

int	init_mlx(t_data *data)
{
	data->mlx.mlx = mlx_init();
	data->mlx.mlx_win = mlx_new_window(data->mlx.mlx, \
	SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	data->mlx.img = mlx_new_image(data->mlx.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	data->mlx.addr = mlx_get_data_addr(data->mlx.img, \
	&data->mlx.bits, &data->mlx.line, &data->mlx.endian);
	ft_xpm_to_img(&data->mlx.text_n, &data->map, &data->mlx, 0);
	ft_xpm_to_img(&data->mlx.text_s, &data->map, &data->mlx, 1);
	ft_xpm_to_img(&data->mlx.text_w, &data->map, &data->mlx, 2);
	ft_xpm_to_img(&data->mlx.text_e, &data->map, &data->mlx, 3);
	return (0);
}

void free_mlx(t_mlx *game)
{
	mlx_destroy_image(game->mlx, game->text_n.img);
	mlx_destroy_image(game->mlx, game->text_s.img);
	mlx_destroy_image(game->mlx, game->text_w.img);
	mlx_destroy_image(game->mlx, game->text_e.img);
	mlx_destroy_image(game->mlx, game->img);
	mlx_clear_window(game->mlx, game->mlx_win);
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
}

int	close_game(t_data *data)
{
	data->mlx.finish = 1;
	free_mlx(&data->mlx);
	free(data->mlx.mlx);
	free_all(&data->map);
	exit(0);
	return (0);
}
