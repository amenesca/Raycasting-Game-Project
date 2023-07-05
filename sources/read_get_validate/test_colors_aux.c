/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_colors_aux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femarque <femarque@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:54:49 by femarque          #+#    #+#             */
/*   Updated: 2023/07/05 13:55:07 by femarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	verify_quant(char ***color)
{
	char	**aux_color;

	aux_color = *color;
	if (count_array(aux_color) != 3)
	{
		free_array(aux_color);
		return (1);
	}
	if (only_numbers(aux_color) > 0)
	{
		free_array(aux_color);
		return (1);
	}
	return (0);
}
