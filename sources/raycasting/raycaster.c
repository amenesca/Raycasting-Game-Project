/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femarque <femarque@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:09:07 by femarque          #+#    #+#             */
/*   Updated: 2023/07/05 13:33:15 by femarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_mlx_pixel_put(t_data *data, int x, int y, int pixel)
{
	char	*dest;

	if (y >= screenHeight || x >= screenWidth || y < 0 || x < 0)
		return ;
	dest = data->mlx.addr + (y * data->mlx.line) \
	+ (x * (data->mlx.bits / 8));
	*(unsigned int *)dest = pixel;
}

void	verline(t_data *data, int x, int start, int end, int color)
{
	int	i;

	i = start;
	while (i <= end)
	{
		ft_mlx_pixel_put(data, x, i, color);
		i++;
	}
}

void	tex_x_coordinate(t_ray *ray)
{
	if (ray->side == 0)
		ray->wallX = ray->playerpos[1] + ray->perp_wall * ray->rayY;
	else
		ray->wallX = ray->playerpos[0] + ray->perp_wall * ray->rayX;
	ray->wallX -= floor(ray->wallX);
	ray->texX = (int)(ray->wallX * (double)(64.0));
	if (ray->side == 0 && ray->rayX > 0)
		ray->texX = 64 - ray->texX - 1;
	if (ray->side == 1 && ray->rayY < 0)
		ray->texX = 64 - ray->texX - 1;
}

void	raycaster(t_data *data)
{
	int	x;

	x = -1;
	put_ceil_floor(data);
	while (++x < screenWidth)
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
