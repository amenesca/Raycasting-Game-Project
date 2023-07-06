/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femarque <femarque@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:44:18 by femarque          #+#    #+#             */
/*   Updated: 2023/07/05 15:54:32 by femarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	movement_y(t_data *data)
{
	float	nextpos_x;
	float	nextpos_y;

	nextpos_x = data->ray.playerpos[0] + data->ray.move_v * \
	(data->ray.dir[0] * data->ray.move_speed);
	nextpos_y = data->ray.playerpos[1] + data->ray.move_v * \
	(data->ray.dir[1] * data->ray.move_speed);
	if (data->map.map[(int)nextpos_x][(int)data->ray.playerpos[1]] == '0')
		data->ray.playerpos[0] = nextpos_x;
	if (data->map.map[(int)data->ray.playerpos[0]][(int)nextpos_y] == '0')
		data->ray.playerpos[1] = nextpos_y;
}

void	movement_x(t_data *data)
{
	float	nextpos_x;
	float	nextpos_y;

	nextpos_x = data->ray.playerpos[0] + data->ray.move_h * \
	(data->ray.plane[0] * data->ray.move_speed);
	nextpos_y = data->ray.playerpos[1] + data->ray.move_h * \
	(data->ray.plane[1] * data->ray.move_speed);
	if (data->map.map[(int)nextpos_x][(int)data->ray.playerpos[1]] == '0')
		data->ray.playerpos[0] = nextpos_x;
	if (data->map.map[(int)data->ray.playerpos[0]][(int)nextpos_y] == '0')
		data->ray.playerpos[1] = nextpos_y;
}

void	mov_camera(t_data *data)
{
	data->ray.rot_speed = data->ray.turn * data->ray.move_speed;
	data->ray.old_dir_x = data->ray.dir[0];
	data->ray.dir[0] = data->ray.dir[0] * cos(data->ray.rot_speed) - \
	data->ray.dir[1] * sin(data->ray.rot_speed);
	data->ray.dir[1] = data->ray.old_dir_x * sin(data->ray.rot_speed) + \
	data->ray.dir[1] * cos(data->ray.rot_speed);
	data->ray.old_plane_x = data->ray.plane[0];
	data->ray.plane[0] = data->ray.plane[0] * cos(data->ray.rot_speed) - \
	data->ray.plane[1] * sin(data->ray.rot_speed);
	data->ray.plane[1] = data->ray.old_plane_x * sin(data->ray.rot_speed) + \
	data->ray.plane[1] * cos(data->ray.rot_speed);
}

int	deal_key(int keycode, t_data *data)
{
	if (keycode == UP)
		data->ray.move_v = 1;
	else if (keycode == DOWN)
		data->ray.move_v = -1;
	else if (keycode == A)
		data->ray.move_h = -1;
	else if (keycode == D)
		data->ray.move_h = 1;
	else if (keycode == RIGHT)
		data->ray.turn = -1;
	else if (keycode == LEFT)
		data->ray.turn = 1;
	else if (keycode == KEY_ESC)
		close_game(data);
	return (0);
}

int	undeal_key(int keycode, t_data *data)
{
	if (keycode == UP)
		data->ray.move_v = 0;
	else if (keycode == DOWN)
		data->ray.move_v = 0;
	else if (keycode == A)
		data->ray.move_h = 0;
	else if (keycode == D)
		data->ray.move_h = 0;
	else if (keycode == RIGHT)
		data->ray.turn = 0;
	else if (keycode == LEFT)
		data->ray.turn = 0;
	return (0);
}
