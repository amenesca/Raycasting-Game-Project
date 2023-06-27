/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femarque <femarque@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:07:36 by amenesca          #+#    #+#             */
/*   Updated: 2023/06/25 16:29:02 by femarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# ifdef __linux__
#  include "../mlx_linux/mlx.h"
# else
#  include "../mlx/mlx.h"
# endif

# include "../libft/libft.h"
# include "./defines.h"
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h> // remover depois

# ifdef __linux__

enum	e_keycode
{
	UP = 119,
	DOWN = 115,
	LEFT = 97,
	RIGHT = 100,
	KEY_ESC = 65307
};
# else

enum	e_keycode
{
	UP = 13,
	DOWN = 1,
	LEFT = 0,
	RIGHT = 2,
	KEY_ESC = 53
};
# endif

typedef struct s_map
{
	char		**map;
	char		**remap;
	char		**file_read;
	char		**textures;
	char		**colors;
	int			*ceiling;
	int			*floor;
	int			file_lines;
	int			map_height;
	int			map_width;
} t_map;
typedef struct s_mlxdata
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bits;
	int			line;
	int			finish;
	int			endian;
} t_mlxdata;

typedef struct s_ray
{
	double	playerpos[2];
	double	dir[2];
	double	plane[2];
	int		mapX;
	int		mapY;
	int		hit;
	int stepX;
	int stepY; //was there a wall hit?
	int side;
	int drawEnd;
	int drawStart;
	int lineHeight;
	double rayDirX;
	double rayDirY;
	double sideDistX;
	double sideDistY;
	double deltaDistX;
	double deltaDistY;
	double cameraX;
	double perpWallDist;
} t_ray;

typedef struct s_data
{
	t_map		map;
	t_mlxdata	mlxdata;
	t_ray		ray;
} t_data;

// treat_args_error.c
int		treat_args_error(int argc, char *argv[]);

// read_map.c
int		count_lines(char *map_path);
void	remove_endl(t_map *map);
int		read_map(char *map_path, t_map *map);

// get_colors_textures.c
int		get_colors_textures(t_map *map);

// validate_colors_textures.c
int		validate_colors_textures(t_map *map);

// split_textures.c
int		split_textures(t_map *map);

// split_colors.c
int		split_colors(t_map *map);

// test_colors.c
int		test_colors(t_map *map);
int		verify_quant(char ***color);
int		only_numbers(char **color);

//get_map.c
int		get_map(t_map *map);

// get_n_validate.c
int		get_n_validate(t_map *map);

// utils
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup_no_endl(const char *s1);
void	free_array(char **array);
int		count_array(char **array);
int		init_pointers(t_map *map);
void	free_all(t_map *map);
int	ft_error(char *s);

// validate_map.c
int		validate_map(t_map *map);

//init_mlx.c
int init_data(t_data *data);
int init_mlx(t_data *data);
int	key_hook(int keycode, t_mlxdata *game);
int	close_game(t_mlxdata *game);

// get_info.c
int		get_info(t_data *data);
void verLine(t_data *data, int x, int y1, int y2, int color);
int divideColorByValue(int color, int value);
void	render(t_data *data);
int deal_key(int keycode, t_mlxdata *data, double moveSpeed, double rotSpeed);

//free_functions
void free_basic(t_map *map);
void free_text_col(t_map *map);
void free_text_col_array(t_map *map);
void free_ceil_floor(t_map *map);

//raycasting
void	side_step(t_data *data);
void	dda(t_data *data);
void config_ray(t_data *data, int x);
void camera_man(t_data *data);
void	ray_line(t_data *data);
int game(t_data *data);

//raycasting_no_textures
void raycasting_no_textures(t_data *data);

// ****** Funcoes para testar coisas ****** apagar depois

void	print_array(char **array);

#endif
