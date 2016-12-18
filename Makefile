# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/12 13:07:31 by jwalsh            #+#    #+#              #
#    Updated: 2016/12/18 16:32:35 by jwalsh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = main.c \
		   fdf.c \
		   read_file.c \
		   set_data.c \
		   init_set_mpts_3d.c \
		   get_2d_coords.c \
		   colors.c \
		   color_palettes.c \
		   reset.c \
		   get.c \
		   mlx_fnct1.c \
		   draw.c \
		   matrix_fnct1.c \
		   matrix_fnct2.c \
		   vector_fnct1.c \
		   vector_fnct2.c \
		   vector_fnct3.c \
		   debugging.c

NAME = fdf

OBJ_NAME = $(SRC_NAME:.c=.o)

HEAD = fdf.h

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LDFLAGS = -LLibft

LDLIBS = -lft

CPPFLAGS = -I.

ECHO = echo

MLX = -lmlx -framework OpenGL -framework AppKit

C_NONE = \033[0m
C_BOLD = \033[1m
C_BLACK = \033[30m
C_RED = \033[31m
C_GREEN = \033[32m
C_BROWN = \033[33m
C_BLUE = \033[34m
C_MAGENTA = \033[35m
C_CYAN = \033[36m
C_GRAY = \033[37m

all: $(NAME)

$(NAME): $(OBJ_NAME)
	@make -C ./Libft
	@make -C ./minilibx_macos/
	@$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -I ./$(HEAD) $(MLX) $^ -o $@
	@$(ECHO) "$(C_GREEN)FDF compilation done.$(C_NONE)"

$(OBJ)%.o: $(SRC)%.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@-/bin/rm -f $(OBJ_NAME)
	@make -C ./Libft clean
	@$(ECHO) "$(C_GREEN)FDF clean done.$(C_NONE)"

fclean: clean
	@-/bin/rm -f $(NAME)
	@make -C ./Libft fclean
	@$(ECHO) "$(C_GREEN)FDF fclean done.$(C_NONE)"

re: fclean
	@$(MAKE) all

PHONY: clean fclean
	@$(ECHO) "$(C_GREEN)FDF .PHONY done.$(C_NONE)"

.PHONY: all clean fclean re
