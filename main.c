/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:07:42 by amenesca          #+#    #+#             */
/*   Updated: 2023/05/23 14:55:24 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int main(int argc, char *argv[]) 
{
	t_map map;

	if (treat_argc(argc) == -1)
		return (-1);
	if (treat_map(argv[1]) == -1)
		return (-1);
	read_map(argv[1], &map);
	if (map.file_read == NULL)
		return (-1);
	print_array(map.file_read);
	
	write(1, "\n\n\n", 3);
	
	print_array(map.textures);
	print_array(map.colors);
	print_array(map.map);
	
	free_array(map.file_read);
	free_array(map.map);
	free_array(map.textures);
//	free_array(map.colors);
	return (0);
}
