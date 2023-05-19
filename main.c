/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:07:42 by amenesca          #+#    #+#             */
/*   Updated: 2023/05/19 17:28:25 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include <stdio.h>

int main(int argc, char *argv[]) 
{
	char **map_read;

	if (treat_argc(argc) == -1)
		return (-1);
	if (treat_map(argv[1]) == -1)
		return (-1);
	map_read = read_map(argv[1]);
	if (map_read == NULL)
		return (-1);
	print_map(map_read);
	
	return (0);
}
