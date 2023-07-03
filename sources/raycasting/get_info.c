/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femarque <femarque@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:08:19 by femarque          #+#    #+#             */
/*   Updated: 2023/06/25 16:18:47 by femarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void set_plane(char c, t_ray *ray)
{
	if (c == 'N')
	{
		ray->plane[0] = 0;
		ray->plane[1] = 0.66;
	}
	else if (c == 'S')
	{
		ray->plane[0] = 0;
		ray->plane[1] = -0.66;
	}
	else if (c == 'W')
	{
		ray->plane[0] = -0.66;
		ray->plane[1] = 0;
	}
	else if (c == 'E')
	{
		ray->plane[0] = 0.66;
		ray->plane[1] = 0;
	}
}

static void set_dir(char c, t_ray *ray)
{
	if (c == 'N')
	{
		ray->dir[0] = -1;
		ray->dir[1] = 0.00000000001;
	}
	else if (c == 'S')
	{
		ray->dir[0] = 1;
		ray->dir[1] = 0.00000000001;
	}
	else if (c == 'W')
	{
		ray->dir[0] = 0.00000000001;
		ray->dir[1] = -1;
	}
	else if (c == 'E')
	{
		ray->dir[0] = 0.00000000001;
		ray->dir[1] = 1;
	}
}

static int is_player(char c, t_ray *ray)
{
	if (c == 'N')
	{
		set_dir(c, ray);
		set_plane(c, ray);
		return (1);
	}
	else if (c == 'E')
	{
		set_dir(c, ray);
		set_plane(c, ray);
		return (1);
	}
	else if (c == 'S')
	{
		set_dir(c, ray);
		set_plane(c, ray);
		return (1);
	}
	else if (c == 'W')
	{
		set_dir(c, ray);
		set_plane(c, ray);
		return (1);
	}
	return (0);
}

static int get_init_pos(t_data *data)
{
	int x;
	int y;

	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			if (is_player(data->map.map[y][x], &data->ray))
			{
				data->ray.playerpos[0] = x + 0.5f; //existem motivos para o +0.5
				data->ray.playerpos[1] = y + 0.5f; //existem motivos para o +0.5
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
	get_hex_colors(data);
	return (0);
}