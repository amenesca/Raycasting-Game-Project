/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:07:36 by amenesca          #+#    #+#             */
/*   Updated: 2023/05/24 18:31:22 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include "../libft/libft.h"
# include "./defines.h"
# include <fcntl.h>
# include <stdio.h> // remover depois
typedef struct s_map
{
	char	**file_read;
	int		file_lines;
	char	**textures;
	char	**colors;
	int		*ceiling;
	int		*floor;
	char	**map;
	char	**remap;
	int		map_height;
	int		map_widht;
} t_map;
typedef struct s_mlxdata
{
	void *mlx;
	void *mlx_win;
	void *img;
	char *addr;
	int bits;
	int line;
	int endian;
} t_mlxdata;
typedef struct s_data
{
	
} t_data;

int		treat_argc(int argc);
int		treat_map(char *map_path);

// Utils
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup_no_endl(const char *s1);
void	free_array(char **array);

// Leitura do mapa

void	free_array(char **array);
int		count_lines(char *map_path);
void	remove_endl(t_map *map);
int		read_map(char *map_path, t_map *map);
int		get_textures(t_map *map);
int		get_colors(t_map *map);

// validate map

int validate_map(t_map *map);

// main
int	init_pointers(t_map *map);
int	validate_elements(t_map *map);

// treat_errors

int count_array(char **array);
int split_textures(t_map *map);
int split_colors(t_map *map);
int test_colors(t_map *map);

// ****** Funcoes para testar coisas ******

void	print_array(char **array);

#endif
