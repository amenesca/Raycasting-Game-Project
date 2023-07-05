/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femarque <femarque@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:28:36 by femarque          #+#    #+#             */
/*   Updated: 2023/07/05 13:34:56 by femarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	divide_color_by_value(int color, int value)
{
	int	red;
	int	green;
	int	blue;

	red = (color & 0xFF0000) >> 16;
	green = (color & 0x00FF00) >> 8;
	blue = color & 0x0000FF;
	red /= value;
	green /= value;
	blue /= value;
	return ((red << 16) | (green << 8) | blue);
}

int	get_pixel_color(t_img *img, int x, int y)
{
	int		color;
	char	*dst;

	dst = img->addr + (y * img->line + x * (img->bits / 8));
	color = *(unsigned int *)dst;
	return (color);
}

void	tex_color(t_data *data, int x)
{
	int	y;
	int	color;

	y = data->ray.draw_start;
	if (y >= screenHeight || x >= screenWidth || y < 0 || x < 0)
		return ;
	data->ray.scale = 1.0 * (double)64 / data->ray.line_height;
	data->ray.texPos = (data->ray.draw_start - screenHeight / 2 + \
	data->ray.line_height / 2) * data->ray.scale;
	while (y < data->ray.draw_end)
	{
		data->ray.texY = (int)data->ray.texPos & (64 - 1);
		data->ray.texPos += data->ray.scale;
		color = get_pixel_color(&data->mlx.text_N, data->ray.texX, \
		data->ray.texY);
		ft_mlx_pixel_put(data, x, y, color);
		y++;
	}
}
