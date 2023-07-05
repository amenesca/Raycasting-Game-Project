/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femarque <femarque@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:28:36 by femarque          #+#    #+#             */
/*   Updated: 2023/07/05 15:56:35 by femarque         ###   ########.fr       */
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

void choose_texture(t_data *data)
{
	if (data->ray.side == 0)
	{
		if (data->ray.rayx < 0)
			data->ray.texture = &data->mlx.text_n;
		else
			data->ray.texture = &data->mlx.text_s;
	}
	else
	{
		if (data->ray.rayy < 0)
			data->ray.texture = &data->mlx.text_w;
		else
			data->ray.texture = &data->mlx.text_e;
    }
}

void	tex_color(t_data *data, int x)
{
	int	y;
	int	color;

	y = data->ray.draw_start;
	if (y >= SCREEN_HEIGHT || x >= SCREEN_WIDTH || y < 0 || x < 0)
		return ;
	data->ray.scale = 1.0 * (double)64 / data->ray.line_height;
	data->ray.tex_pos = (data->ray.draw_start - SCREEN_HEIGHT / 2 + \
	data->ray.line_height / 2) * data->ray.scale;
	while (y < data->ray.draw_end)
	{
		data->ray.tex_y = (int)data->ray.tex_pos & (64 - 1);
		data->ray.tex_pos += data->ray.scale;
		color = get_pixel_color(data->ray.texture, data->ray.tex_x, \
		data->ray.tex_y);
		ft_mlx_pixel_put(data, x, y, color);
		y++;
	}
}
