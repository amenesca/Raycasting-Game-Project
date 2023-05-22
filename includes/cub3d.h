/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:07:36 by amenesca          #+#    #+#             */
/*   Updated: 2023/05/22 16:14:24 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include "../libft/libft.h"
# include <fcntl.h>

typedef struct s_map {
	char **map_read;
	char **textures;
	
} t_map;

int		treat_argc(int argc);
int		treat_map(char *map_path);

// Utils
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup_no_endl(const char *s1);
void	free_array(char **array);

// Leitura do mapa

void	free_array(char **array);
int		count_lines(char *map_path);
void	remove_endl(t_map *map, int lines);
void	read_map(char *map_path, t_map *map);
void	get_textures_path(t_map *map);


// ****** Funcoes para testar coisas ******

void	print_array(char **array);

#endif