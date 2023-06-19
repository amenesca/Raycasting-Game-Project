/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femarque <femarque@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:07:42 by amenesca          #+#    #+#             */
/*   Updated: 2023/06/19 18:39:45 by femarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int argc, char *argv[]) 
{
	t_data data;

	if (treat_args_error(argc, argv) != 0)
		return (-1);
	init_pointers(&data.map);
	if (read_map(argv[1], &data.map) != 0)
	{
		free_all(&data.map);
		return (-1);
	}
	if (data.map.file_read == NULL)
	{
		free_all(&data.map);
		return (-1);
	}
	if (get_n_validate(&data.map) != 0)
	{
		free_all(&data.map);
		return (-1);
	}
	print_array(data.map.file_read);
	print_array(data.map.textures);
//	print_array(data.map.colors);
//	print_array(data.map.map);
	print_array(data.map.remap);
	
	get_info(&data);
	init_data(&data);
	mlx_hook(data.mlxdata.mlx_win, 2, 1L << 0, &key_hook, &data.mlxdata);
	mlx_hook(data.mlxdata.mlx_win, 17, 1L << 2, &close_game, &data.mlxdata);
	mlx_loop(data.mlxdata.mlx);
	free_all(&data.map);
	return (0);
}