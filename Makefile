# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmago <mmago@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 16:02:39 by mmago             #+#    #+#              #
#    Updated: 2022/04/11 21:08:56 by mmago            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIB_PATH = ./includes/libft/
LIB_NAME = ./includes/libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

FILES = src/so_long.c src/check_map.c src/ft_error.c src/p_move.c \
		src/key_hook.c src/img_init.c src/animation.c src/ft_render.c
					
OBJS = $(FILES:%.c=%.o)

MLX_FLAGS = -L . -lmlx -framework OpenGL -framework AppKit

$(NAME): $(OBJS) $(LIB_NAME)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(LIB_NAME) $(OBJS) -o $(NAME)


all: $(NAME)

${LIB_NAME}: libft;

libft:
	${MAKE} -C ${LIB_PATH} all

clean:
	$(RM) $(OBJS)
	${MAKE} -C ${LIB_PATH} clean

fclean: clean
	$(RM) $(NAME)
	${MAKE} -C ${LIB_PATH} fclean

re: fclean all

.PHONY:all clean fclean re libft
