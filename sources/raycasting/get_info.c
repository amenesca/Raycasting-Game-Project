#include "../../includes/cub3d.h"

int is_player(char c, t_raycastdat *raycastdat)
{
	if (c == 'N')
	{
		raycastdat->dir[0] = 0;
		raycastdat->dir[1] = 1;
		return (1);
	}
	else if (c == 'E')
	{
		raycastdat->dir[0] = 1;
		raycastdat->dir[1] = 0;
		return (1);
	}
	else if (c == 'S')
	{
		raycastdat->dir[0] = 0;
		raycastdat->dir[1] = -1;
		return (1);
	}
	else if (c == 'W')
	{
		raycastdat->dir[0] = -1;
		raycastdat->dir[1] = 0;
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
				data->raycastdat.playerpos[0] = x;
				data->raycastdat.playerpos[1] = y;
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

/*static int get_map_size(t_data *data)
{
	
}*/

int get_info(t_data *data)
{
	get_init_pos(data);
/*	printf("%d\n%d\n%c\n%d\n%d\n", data->raycastdat.playerpos[0],\
	data->raycastdat.playerpos[1], \
	data->map.map[data->raycastdat.playerpos[1]][data->raycastdat.playerpos[0]],\
	data->raycastdat.dir[0], data->raycastdat.dir[1]);*/
//	get_map_size();
	return (0);
}