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

// treat_args_error.c
int treat_args_error(int argc, char *argv[]);

// read_map.c
int		count_lines(char *map_path);
void	remove_endl(t_map *map);
int		read_map(char *map_path, t_map *map);

// get_colors_textures.c
int get_colors_textures(t_map *map);

// validate_colors_textures.c
int	validate_colors_textures(t_map *map);

// split_textures.c
int split_textures(t_map *map);

// split_colors.c
int split_colors(t_map *map);

// test_colors.c
int test_colors(t_map *map);

//get_map.c
int get_map(t_map *map);

// get_n_validate
int get_n_validate(t_map *map);

// Utils
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup_no_endl(const char *s1);
void	free_array(char **array);

// Leitura do mapa

void	free_array(char **array);

// validate map

int validate_map(t_map *map);

// main
int	init_pointers(t_map *map);

// treat_errors

int count_array(char **array);

// ****** Funcoes para testar coisas ******

void	print_array(char **array);

#endif
