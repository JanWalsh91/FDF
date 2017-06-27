# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/12 13:07:31 by jwalsh            #+#    #+#              #
#    Updated: 2017/06/27 13:37:06 by jwalsh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libmathft.a

COMPLEX_NUMBERS = c_add \
		c_add_float \
		c_abs \
		c_divide \
		c_product \
		c_product_double \
		c_minus \
		c_minus_double \
		c_modulus \
		c_sin \
		c_sphere \
		c_horseshoe \
		c_swirl \
		c_polar

VECTORS_AND_MATRICES = m_new \
		m_new_identity \
		m_new_scale \
		m_new_rotate \
		m_new_rodriguez \
		m_translate \
		m_v_mult \
		m_p_mult \
		m_mult \
		m_add \
		m_scale \
		v_new \
		v_to_rot_matrix \
		v_dot \
		v_length \
		v_norm \
		v_cross \
		v_add \
		v_sub \
		v_mult \
		v_scale \
		v_clamp \
		v_isnan

MISC = 	ft_abs \
		ft_power \
		ft_round \
		ft_rgb_mix \
		ft_to_radian

OBJ_DIR = obj

EXT = .c

SRC_COMPLEX_NUMBERS = $(addsuffix $(EXT), $(COMPLEX_NUMBERS))
SRC_VECTORS_AND_MATRICES = $(addsuffix $(EXT), $(VECTORS_AND_MATRICES))
SRC_MISC = $(addsuffix $(EXT), $(MISC))
OBJ_COMPLEX_NUMBERS = $(addprefix $(OBJ_DIR)/, $(SRC_COMPLEX_NUMBERS:.c=.o))
OBJ_VECTORS_AND_MATRICES = $(addprefix $(OBJ_DIR)/, $(SRC_VECTORS_AND_MATRICES:.c=.o))
OBJ_MISC = $(addprefix $(OBJ_DIR)/, $(SRC_MISC:.c=.o))

HEAD = libmathft.h

CC = gcc

CFLAGS = -Wall -Werror -Wextra

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

$(NAME): $(OBJ_COMPLEX_NUMBERS) $(OBJ_VECTORS_AND_MATRICES) $(OBJ_MISC) 
	@ar rcs $(NAME) $(OBJ_COMPLEX_NUMBERS) $(OBJ_VECTORS_AND_MATRICES) $(OBJ_MISC)
	@echo "$(C_CYAN)Libmathft compilation done.$(C_NONE)"

$(OBJ_DIR)/%.o : ./complex_numbers/%.c
	@/bin/mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I./inc -c -o $@ $<

$(OBJ_DIR)/%.o : ./vectors_and_matrices/%.c
	@/bin/mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I./inc -c -o $@ $<

$(OBJ_DIR)/%.o : ./misc/%.c
	@/bin/mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I./inc -c -o $@ $<

clean:
	@/bin/rm -Rf $(OBJ_DIR)
	@echo "$(C_CYAN)Libmathft clean done.$(C_NONE)"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "$(C_CYAN)Libmathft fclean done.$(C_NONE)"

re: fclean
	@$(MAKE) all

.PHONY: clean fclean
	@echo "$(C_CYAN)Libmathft .PHONY done.$(C_NONE)"
