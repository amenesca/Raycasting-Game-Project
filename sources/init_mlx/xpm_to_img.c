/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_to_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femarque <femarque@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:04:13 by femarque          #+#    #+#             */
/*   Updated: 2023/07/05 12:05:55 by femarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_xpm_to_img(t_img *imgtex, t_map *map, t_mlx *mlx, int pos)
{
	imgtex->img = mlx_xpm_file_to_image(mlx->mlx, \
	map->textures[pos], &imgtex->tex_width, &imgtex->tex_height);
	imgtex->addr = NULL;
	imgtex->addr = mlx_get_data_addr(imgtex->img, \
	&imgtex->bits, &imgtex->line, &imgtex->endian);
}
