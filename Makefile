# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/12 13:07:31 by jwalsh            #+#    #+#              #
#    Updated: 2016/12/31 17:20:17 by jwalsh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = main.c \
		   fdf.c \
		   read_file.c \
		   set_data.c \
		   coords_2d.c \
		   mpts_3d.c \
		   instructions.c \
		   colors.c \
		   color_palettes.c \
		   reset.c \
		   get.c \
		   draw.c \
		   win_img.c \
		   mlx_fnct1.c \
		   mlx_fnct2.c \
		   free_all.c

NAME = fdf

OBJ_NAME = $(SRC_NAME:.c=.o)

HEAD = include/

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
	@make -C ./Libmathft
	@$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -LLibmathft -lmathft -I ./$(HEAD) $(MLX) $^ -o $@
	@$(ECHO) "$(C_GREEN)FDF compilation done.$(C_NONE)"

$(OBJ)%.o: $(SRC)%.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@-/bin/rm -f $(OBJ_NAME)
	@make -C ./Libft clean
	@make -C ./Libmathft clean
	@$(ECHO) "$(C_GREEN)FDF clean done.$(C_NONE)"

fclean: clean
	@-/bin/rm -f $(NAME)
	@make -C ./Libft fclean
	@make -C ./Libmathft/ fclean
	@$(ECHO) "$(C_GREEN)FDF fclean done.$(C_NONE)"

re: fclean
	@$(MAKE) all

PHONY: clean fclean
	@$(ECHO) "$(C_GREEN)FDF .PHONY done.$(C_NONE)"

.PHONY: all clean fclean re
