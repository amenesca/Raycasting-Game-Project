/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femarque <femarque@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:07:36 by amenesca          #+#    #+#             */
/*   Updated: 2023/07/05 19:55:08 by femarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# ifdef __linux__
#  include "../libs/mlx_linux/mlx.h"
# else
#  include "../libs/mlx/mlx.h"
# endif

# include "../libs/libft/libft.h"
# include "./defines.h"
# include <math.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_map {
	char	**map;
	char	**remap;
	char	**file_read;
	char	**textures;
	char	**colors;
	int		*ceiling;
	int		*floor;
	int		file_lines;
	int		map_height;
	int		map_width;
}	t_map;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits;
	int		line;
	int		endian;
	int		tex_height;
	int		tex_width;
}	t_img;

typedef struct s_mlx {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits;
	int		line;
	int		finish;
	int		endian;
	t_img	text_n;
	t_img	text_s;
	t_img	text_e;
	t_img	text_w;
}	t_mlx;

typedef struct s_ray {
	double	playerpos[2];
	double	dir[2];
	double	move_v;
	double	move_h;
	double	plane[2];
	int		mapx;
	int		mapy;
	int		hit;
	double	stepx;
	double	stepy;
	int		side;
	int		draw_end;
	int		draw_start;
	int		line_height;
	double	rayx;
	double	rayy;
	double	sidex;
	double	sidey;
	double	deltax;
	double	deltay;
	double	camerax;
	double	perp_wall;
	double	old_dir_x;
	double	old_plane_x;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	scale;
	double	tex_pos;
	int		ceil_color;
	int		floor_color;
	double	move_speed;
	double	rot_speed;
	double	turn;
	t_img	*texture;
}	t_ray;

typedef struct s_data {
	t_map	map;
	t_mlx	mlx;
	t_ray	ray;
}	t_data;

char	*ft_strdup_no_endl(const char *s1);
int		is_valid_char(char c);
int		validade_char(t_map *map);
int		treat_args_error(int argc, char *argv[]);
int		count_lines(char *map_path);
int		read_map(char *map_path, t_map *map);
int		get_colors_textures(t_map *map);
int		validate_colors_textures(t_map *map);
int		split_textures(t_map *map);
int		split_colors(t_map *map);
int		test_colors(t_map *map);
int		verify_quant(char ***color);
int		only_numbers(char **color);
int		get_map(t_map *map);
int		get_n_validate(t_map *map);
int		ft_strcmp(const char *s1, const char *s2);
int		count_array(char **array);
int		init_pointers(t_map *map);
int		ft_error(char *s);
int		validate_map(t_map *map);
int		init_data(t_data *data);
int		init_mlx(t_data *data);
int		close_game(t_mlx *game);
int		deal_key(int keycode, t_data *data);
int		undeal_key(int keycode, t_data *data);
int		divide_color_by_value(int color, int value);
int		get_pixel_color(t_img *img, int x, int y);
int		get_info(t_data *data);
int		divide_color_by_value(int color, int value);
int		game(t_data *data);
void	raycaster(t_data *data);
void	ft_mlx_pixel_put(t_data *data, int x, int y, int pixel);
void	calculate4(t_ray *ray);
void	calculate3(t_ray *ray, t_map *map);
void	calculate2(t_ray *ray);
void	calculate1(t_ray *ray, int x);
void	choose_texture(t_data *data);
void	fill_out_spaces(t_map *map);
void	get_map_width(t_map *map);
void	remove_endl(t_map *map);
void	free_array(char **array);
void	free_all(t_map *map);
void	ft_xpm_to_img(t_img *imgtex, t_map *map, t_mlx *mlx, int pos);
void	tex_color(t_data *data, int x);
void	movement_y(t_data *data);
void	movement_x(t_data *data);
void	mov_camera(t_data *data);
void	free_basic(t_map *map);
void	free_text_col(t_map *map);
void	free_text_col_array(t_map *map);
void	free_ceil_floor(t_map *map);
void	get_hex_colors(t_data *data);
void	put_ceil_floor(t_data *data);

#endif
