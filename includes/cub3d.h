/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:07:36 by amenesca          #+#    #+#             */
/*   Updated: 2023/05/22 14:36:48 by amenesca         ###   ########.fr       */
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

int	treat_argc(int argc);
int treat_map(char *map_path);
int	ft_strcmp(const char *s1, const char *s2);

// Leitura do mapa

int		count_lines(char *map_path);
char	*free_strtrim(char const *s1, char const *set);
void	remove_endl(char **map_read);
void	read_map(char *map_path, t_map *map);


// ****** Funcoes para testar coisas ******

void print_map(char **map_read);

#endif