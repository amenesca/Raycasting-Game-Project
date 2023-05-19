/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:07:36 by amenesca          #+#    #+#             */
/*   Updated: 2023/05/19 17:27:37 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include "../libft/libft.h"
# include <fcntl.h>

typedef struct s_map {
	char **map_info;
} t_map;

int	treat_argc(int argc);
int treat_map(char *map_path);
int	ft_strcmp(const char *s1, const char *s2);
int	count_lines(char *map_path);
char **read_map(char *map_path);


// ****** Funcoes para testar coisas ******

void print_map(char **map_read);

#endif