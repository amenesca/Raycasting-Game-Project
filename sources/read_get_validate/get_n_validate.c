/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_n_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femarque <femarque@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:51:17 by femarque          #+#    #+#             */
/*   Updated: 2023/07/05 13:51:26 by femarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_n_validate(t_map *map)
{	
	if (get_colors_textures(map) != 0)
		return (1);
	if (validate_colors_textures(map) > 0)
		return (1);
	if (test_colors(map) > 0)
		return (1);
	if (get_map(map) != 0)
		return (1);
	if (validate_map(map) != 0)
		return (1);
	return (0);
}
