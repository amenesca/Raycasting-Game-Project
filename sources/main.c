/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femarque <femarque@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:07:42 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/05 15:54:21 by femarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data.ray.move_speed = 0.0035;
	if (treat_args_error(argc, argv) != 0)
		return (-1);
	init_pointers(&data.map);
	if (read_map(argv[1], &data.map) != 0)
		return (-1);
	if (get_n_validate(&data.map) != 0)
		return (-1);
	get_info(&data);
	init_data(&data);
	mlx_hook(data.mlx.mlx_win, 2, (1L << 0), deal_key, &data);
	mlx_hook(data.mlx.mlx_win, 3, (1L << 1), undeal_key, &data);
	mlx_hook(data.mlx.mlx_win, 17, (1L << 2), close_game, &data.mlx);
	mlx_loop_hook(data.mlx.mlx, &game, &data);
	mlx_loop(data.mlx.mlx);
	free_all(&data.map);
	return (0);
}
