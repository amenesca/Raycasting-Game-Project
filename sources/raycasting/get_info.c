#include "../../includes/cub3d.h"

static void set_plane(char c, t_raycastdat *raycastdat)
{
	if (c == 'N')
	{
		raycastdat->plane[0] = 0.66;
		raycastdat->plane[1] = 0;
	}
	else if (c == 'S')
	{
		raycastdat->plane[0] = -0.66;
		raycastdat->plane[1] = 0;
	}
	else if (c == 'W')
	{
		raycastdat->plane[0] = 0;
		raycastdat->plane[1] = 0.66;
	}
	else if (c == 'E')
	{
		raycastdat->plane[0] = 0;
		raycastdat->plane[1] = -0.66;
	}
}

static void set_dir(char c, t_raycastdat *raycastdat)
{
	if (c == 'N')
	{
		raycastdat->dir[0] = 0;
		raycastdat->dir[1] = 1;
	}
	else if (c == 'S')
	{
		raycastdat->dir[0] = 0;
		raycastdat->dir[1] = -1;
	}
	else if (c == 'W')
	{
		raycastdat->dir[0] = -1;
		raycastdat->dir[1] = 0;
	}
	else if (c == 'E')
	{
		raycastdat->dir[0] = 1;
		raycastdat->dir[1] = 0;
	}
}

static int is_player(char c, t_raycastdat *raycastdat)
{
	if (c == 'N')
	{
		set_dir(c, raycastdat);
		set_plane(c, raycastdat);
		return (1);
	}
	else if (c == 'E')
	{
		set_dir(c, raycastdat);
		set_plane(c, raycastdat);
		return (1);
	}
	else if (c == 'S')
	{
		set_dir(c, raycastdat);
		set_plane(c, raycastdat);
		return (1);
	}
	else if (c == 'W')
	{
		set_dir(c, raycastdat);
		set_plane(c, raycastdat);
		return (1);
	}
	return (0);
}

static int get_init_pos(t_data *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			if (is_player(data->map.map[y][x], &data->raycastdat))
			{
				data->raycastdat.playerpos[0] = x + 0.5f; //existem motivos para o +0.5
				data->raycastdat.playerpos[1] = y + 0.5f; //existem motivos para o +0.5
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int get_info(t_data *data)
{
	get_init_pos(data);
// PRINTF FROM HELL ***
/*	printf("player pos x: %f\n\
player pos y: %f\nplayer: %c\n\
player dir x: %f\nplayer dir y %f\n\
plane x: %f\nplane y: %f\n",\
data->raycastdat.playerpos[0],\
data->raycastdat.playerpos[1], \
data->map.map[(int)data->raycastdat.playerpos[1]][(int)data->raycastdat.playerpos[0]],\
data->raycastdat.dir[0], data->raycastdat.dir[1], data->raycastdat.plane[0], data->raycastdat.plane[1]);*/
	return (0);
}