/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femarque <femarque@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:09:07 by femarque          #+#    #+#             */
/*   Updated: 2023/07/05 15:56:35 by femarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_mlx_pixel_put(t_data *data, int x, int y, int pixel)
{
	char	*dest;

	if (y >= SCREEN_HEIGHT || x >= SCREEN_WIDTH || y < 0 || x < 0)
		return ;
	dest = data->mlx.addr + (y * data->mlx.line) \
	+ (x * (data->mlx.bits / 8));
	*(unsigned int *)dest = pixel;
}

void	tex_x_coordinate(t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_x = ray->playerpos[1] + ray->perp_wall * ray->rayy;
	else
		ray->wall_x = ray->playerpos[0] + ray->perp_wall * ray->rayx;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)(64.0));
	if (ray->side == 0 && ray->rayx > 0)
		ray->tex_x = 64 - ray->tex_x - 1;
	if (ray->side == 1 && ray->rayy < 0)
		ray->tex_x = 64 - ray->tex_x - 1;
}

void	raycaster(t_data *data)
{
	int	x;

	x = -1;
	put_ceil_floor(data);
	while (++x < SCREEN_WIDTH)
	{
		calculate1(&data->ray, x);
		calculate2(&data->ray);
		calculate3(&data->ray, &data->map);
		calculate4(&data->ray);
		tex_x_coordinate(&data->ray);
		tex_color(data, x);
	}
	mlx_put_image_to_window(data->mlx.mlx, \
	data->mlx.mlx_win, data->mlx.img, 0, 0);
}

int	game(t_data *data)
{
	raycaster(data);
	movement_y(data);
	movement_x(data);
	mov_camera(data);
	return (0);
}
