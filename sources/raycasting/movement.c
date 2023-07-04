/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femarque <femarque@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:44:18 by femarque          #+#    #+#             */
/*   Updated: 2023/07/04 16:28:53 by femarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void movement_y(t_data *data)
{
    float nextPosX;
    float nextPosY;
	
	nextPosX = data->ray.playerpos[0] + data->ray.move_v * (data->ray.dir[0] * data->ray.moveSpeed);
	nextPosY = data->ray.playerpos[1] + data->ray.move_v * (data->ray.dir[1] * data->ray.moveSpeed);

    //if (data->map.map[(int)nextPosX][(int)data->ray.playerpos[1]] == '0')
    data->ray.playerpos[0] = nextPosX;
    //if (data->map.map[(int)data->ray.playerpos[0]][(int)nextPosY] == '0')
    data->ray.playerpos[1] = nextPosY;
}

void movement_x(t_data *data)
{
	float nextPosX;
	float nextPosY;

    nextPosX = data->ray.playerpos[0] + data->ray.move_h * (data->ray.plane[0] * data->ray.moveSpeed);
    nextPosY = data->ray.playerpos[1] + data->ray.move_h * (data->ray.plane[1] * data->ray.moveSpeed);

    //if (data->map.map[(int)nextPosX][(int)data->ray.playerpos[1]] == '0')
    data->ray.playerpos[0] = nextPosX;
    //if (data->map.map[(int)data->ray.playerpos[0]][(int)nextPosY] == '0')
    data->ray.playerpos[1] = nextPosY;
}

void	mov_camera(t_data *data)
{
	data->ray.rotSpeed = data->ray.turn * data->ray.moveSpeed;
	
	data->ray.oldDirX = data->ray.dir[0];
	data->ray.dir[0] = data->ray.dir[0] * cos(data->ray.rotSpeed) - data->ray.dir[1] * sin(data->ray.rotSpeed);
	data->ray.dir[1] = data->ray.oldDirX * sin(data->ray.rotSpeed) + data->ray.dir[1] * cos(data->ray.rotSpeed);
	data->ray.oldPlaneX = data->ray.plane[0];
	data->ray.plane[0] = data->ray.plane[0] * cos(data->ray.rotSpeed) - data->ray.plane[1] * sin(data->ray.rotSpeed);
	data->ray.plane[1] = data->ray.oldPlaneX * sin(data->ray.rotSpeed) + data->ray.plane[1] * cos(data->ray.rotSpeed);
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
		data->ray.turn = 1;
	else if (keycode == LEFT)
		data->ray.turn = -1;
	else if (keycode == KEY_ESC)
		close_game(&data->mlxdata);
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
