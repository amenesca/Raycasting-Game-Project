#include "../../includes/cub3d.h"

void paint_it_black(t_data *data)
{
	int x;
	int y;

	y = -1;
	while (++y < h)
	{
		x = -1;
		while (++x < w)
			ft_mlx_pixel_put(data, x, y, 0x000000);
	}
	return ;
}

int handle_keys(int keycode, t_data *data)
{
	double moveSpeed = 0.5;
	double rotSpeed = 0.5;

	if (keycode == 119) //up
	{
		if (data->map.map[(int)(data->ray.playerpos[0] + data->ray.dir[0] * moveSpeed)][(int)data->ray.playerpos[1]] == '0')
			data->ray.playerpos[0] += data->ray.dir[0] * moveSpeed;
		if (data->map.map[(int)data->ray.playerpos[0]][(int)(data->ray.playerpos[1] + data->ray.dir[1] * moveSpeed)] == '0')
			data->ray.playerpos[1] += data->ray.dir[1] * moveSpeed;
		paint_it_black(data);
		mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.mlx_win, data->mlxdata.img, 0, 0);
		data->ray.flag = 1;
		return (0);
	}
	if (keycode == 115) //down
	{
		if(data->map.map[(int)(data->ray.playerpos[0] - data->ray.dir[0] * moveSpeed)][(int)(data->ray.playerpos[1])] == '0')
			data->ray.playerpos[0] -= data->ray.dir[0] * moveSpeed;
		if(data->map.map[(int)(data->ray.playerpos[0])][(int)(data->ray.playerpos[1] - data->ray.dir[1] * moveSpeed)] == '0')
			data->ray.playerpos[1] -= data->ray.dir[1] * moveSpeed;
		paint_it_black(data);
		mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.mlx_win, data->mlxdata.img, 0, 0);
		data->ray.flag = 1;
	}
	if (keycode == 97) //left
	{
		data->ray.oldDirX = data->ray.dir[0];
		data->ray.dir[0] = data->ray.dir[0] * cos(rotSpeed) - data->ray.dir[1] * sin(rotSpeed);
		data->ray.dir[1] = data->ray.oldDirX * sin(rotSpeed) + data->ray.dir[1] * cos(rotSpeed);
		data->ray.oldPlaneX = data->ray.plane[0];
		data->ray.plane[0] = data->ray.plane[0] * cos(rotSpeed) - data->ray.plane[1] * sin(rotSpeed);
		data->ray.plane[1] = data->ray.oldPlaneX * sin(rotSpeed) + data->ray.plane[1] * cos(rotSpeed);
		paint_it_black(data);
		mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.mlx_win, data->mlxdata.img, 0, 0);
		data->ray.flag = 1;
	}
	if (keycode == 100) // right
	{
		data->ray.oldDirX = data->ray.dir[0];
		data->ray.dir[0] = data->ray.dir[0] * cos(-rotSpeed) - data->ray.dir[1] * sin(-rotSpeed);
		data->ray.dir[1] = data->ray.oldDirX * sin(-rotSpeed) + data->ray.dir[1] * cos(-rotSpeed);
		data->ray.oldPlaneX = data->ray.plane[0];
		data->ray.plane[0] = data->ray.plane[0] * cos(-rotSpeed) - data->ray.plane[1] * sin(-rotSpeed);
		data->ray.plane[1] = data->ray.oldPlaneX * sin(-rotSpeed) + data->ray.plane[1] * cos(-rotSpeed);
		paint_it_black(data);
		mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.mlx_win, data->mlxdata.img, 0, 0);
		data->ray.flag = 1;
	}
	return (0);
}