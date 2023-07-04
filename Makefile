# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: femarque <femarque@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 14:08:11 by amenesca          #+#    #+#              #
#    Updated: 2023/07/04 13:57:11 by femarque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

detected_OS := $(shell uname)
ifeq ($(detected_OS),Linux)
MLXFLAGS	=	-L ./mlx_linux/ -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
RUN		=	make -s -C ./mlx_linux/
CLEAN	=	make clean -s -C ./mlx_linux/
CFLAGS	= 	-Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3
else
MLXFLAGS 	=	-L ./mlx/ -Lmlx -lmlx -framework OpenGL -framework AppKit
RUN 	=	make -s -C ./mlx/
CLEAN 	=	make clean -s -C ./mlx/
CFLAGS	=	-Wall -Wextra -Werror -Imlx
endif

NAME 		= cub3d

LIBFT		= ./libft/libft.a

SRCS		= ./sources/main.c ./sources/treat_initial_errors/treat_args_errors.c ./sources/utils/error.c ./sources/utils/utils.c\
 ./sources/utils/utils2.c tests_purpose_functions.c\
 ./sources/read_get_validate/get_colors_textures.c ./sources/read_get_validate/read_map.c ./sources/read_get_validate/validate_colors_textures.c\
 ./sources/read_get_validate/split_colors.c ./sources/read_get_validate/split_textures.c ./sources/read_get_validate/validate_map.c\
 ./sources/read_get_validate/test_colors.c ./sources/read_get_validate/get_map.c ./sources/read_get_validate/get_n_validate.c\
 ./sources/init_mlx/init_mlx.c ./sources/raycasting/get_info.c ./sources/free_functions/free_functions.c\
 ./sources/read_get_validate/test_colors_aux.c ./sources/raycasting/raycaster.c ./sources/raycasting/handle_keys.c\
 ./sources/init_mlx/xpm_to_img.c ./sources/raycasting/get_hex_colors.c ./sources/raycasting/movement.c\

OBJS		= $(SRCS:.c=.o)

RM			= rm -f

.c.o:
			@cc $(CFLAGS) -c $< -o $(<:.c=.o) -I ./includes

$(NAME):	$(OBJS)
				@make -C ./libft
				$(RUN)
				cc $(OBJS) $(MLXFLAGS) $(LIBFT) -o $(NAME)
				printf "COMPILATION SUCCESSFUL!\n"

all:		$(NAME)

clean:
			@$(RM) $(OBJS)
				$(CLEAN)
				@make clean -C ./libft

fclean:		clean
				@$(RM) $(NAME)
				@make fclean -C ./libft
				printf "FULLY CLEANED!\n"

re:			fclean all

.SILENT:

.PHONY:		all clean fclean re