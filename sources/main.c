/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:07:42 by amenesca          #+#    #+#             */
/*   Updated: 2023/06/06 11:58:05 by amenesca         ###   ########.fr       */
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
	
//	get_info(&data);
//	init_mlx(&data.mlxdata);
//	mlx_loop(data.mlxdata.mlx);
	free_all(&data.map);
	return (0);
}