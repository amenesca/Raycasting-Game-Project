#include "../../includes/cub3d.h"

int handle_keys(int keycode, t_data *data)
{
	double moveSpeed = 1.1;

	if (keycode == 119)
	{
		ft_putnbr_fd(keycode, 1);
		if (data->map.map[(int)(data->ray.playerpos[0]\
		 + data->ray.dir[0]\
		  * moveSpeed)][(int)data->ray.playerpos[1]] == '0')
			data->ray.playerpos[0] += data->ray.dir[0] * moveSpeed;
		if (data->map.map[(int)data->ray.playerpos[0]]\
		[(int)(data->ray.playerpos[1]\
		 + data->ray.dir[1] * moveSpeed)] == '0')
			data->ray.playerpos[1] += data->ray.dir[1] * moveSpeed;
		data->ray.flag = 1;
		return (0);
	}
/*	if (keycode == DOWN)
	{

	}
	if (keycode == LEFT)
	{

	}
	if (keycode == RIGHT)
	{

	}*/
	return (0);
}