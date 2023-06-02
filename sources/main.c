/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:07:42 by amenesca          #+#    #+#             */
/*   Updated: 2023/05/24 18:23:37 by maragao          ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int argc, char *argv[]) 
{
	t_map map;

	if (treat_args_error(argc, argv) != 0)
		return (-1);
	init_pointers(&map);
	if (read_map(argv[1], &map) != 0)
	{
		free_all(&map);
		return (-1);
	}
	if (map.file_read == NULL)
	{
		free_all(&map);
		return (-1);
	}
	if (get_n_validate(&map) != 0)
	{
		free_all(&map);
		return (-1);
	}
	print_array(map.file_read);
	print_array(map.textures);
	print_array(map.colors);
	print_array(map.map);
	print_array(map.remap);

	free_all(&map);
	return (0);
}

/*HEAP SUMMARY:
==19154==     in use at exit: 1,404,803 bytes in 814 blocks
==19154==   total heap usage: 1,007 allocs, 193 frees, 2,590,568 bytes allocated
==19154== 
==19154== LEAK SUMMARY:
==19154==    definitely lost: 10,793 bytes in 225 blocks
==19154==    indirectly lost: 5,664 bytes in 130 blocks
==19154==      possibly lost: 472 bytes in 10 blocks
==19154==    still reachable: 11,272 bytes in 60 blocks
==19154==         suppressed: 1,376,602 bytes in 389 blocks*/