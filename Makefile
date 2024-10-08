# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sueno-te <rflseijiueno@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 05:26:51 by sueno-te          #+#    #+#              #
#    Updated: 2024/05/22 16:50:59 by sueno-te         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#DEFAULTS#
NAME				=	fractol
CC					=	cc
CC_FLAGS			=	-Wall	\
						-Wextra	\
						-Werror	\
						-O2

#PROJECT DIRECTORIES#
SRC_DIR				=	src
INCLUDE_DIR			=	include
INCLUDE_FILES		=	fractol.h
INCLUDES			=	$(addprefix $(INCLUDE_DIR)/, $(INCLUDE_FILES))
BUILD_DIR			=	build
SRC_FILES			=	draw_fractal.c	\
						init_fractal.c	\
						err.c			\
						hooks.c			\
						init.c			\
						fractal.c		\
						main.c			\
						zoom.c		\
						rgba.c
SRCS				=	$(addprefix $(SRC_DIR)/, SRC_FILES)
OBJS				=	$(SRC_FILES:.c=.o)
BUILDS				=	$(addprefix $(BUILD_DIR)/, $(OBJS))

#libft#
LIBFT_LIB_NAME		=	libft.a
LIBFT_DIR			=	libft
LIBFT_INCLUDE_DIR	=	$(LIBFT_DIR)/include
LIBFT_LIB			=	$(LIBFT_DIR)/$(LIBFT_LIB_NAME)
LIBFT_LIBS			=	-lft
LIBFT_CC			=	-I./$(LIBFT_INCLUDE_DIR)	\
						-L./$(LIBFT_DIR)			\
						$(LIBFT_LIBS)

#MLX42#
MLX42_LIB_NAME		=	libmlx42.a
MLX42_DIR			=	MLX42
MLX42_INCLUDE_DIR	=	$(MLX42_DIR)/include
MLX42_BUILD_DIR		=	$(MLX42_DIR)/build
MLX42_LIB			=	$(MLX42_BUILD_DIR)/$(MLX42_LIB_NAME)
MLX42_LIBS			=	-lmlx42		\
						-ldl		\
						-lglfw		\
						-pthread	\
						-lm
MLX42_CC			=	-I./$(MLX42_INCLUDE_DIR)	\
						-L./$(MLX42_BUILD_DIR)		\
						$(MLX42_LIBS)

#COLOR#
BLUE				=	\033[0;34m
CYAN				=	\033[0;36m
GREEN				=	\033[0;32m
YELLOW				=	\033[0;33m
DEFAULT 			=	\033[0:0m

#RULES#
.PHONY: all bonus clean fclean clear re

all: $(NAME)

bonus: $(NAME)

$(NAME): $(MLX42_LIB) $(LIBFT_LIB) $(BUILD_DIR) $(BUILDS) $(INCLUDES)
	@ $(CC) -o $(NAME)	\
	  $(BUILDS)			\
	  -I./$(INCLUDE_DIR)\
	  $(MLX42_CC)		\
	  $(LIBFT_CC)		\
	  $(CC_FLAGS)
	@ printf "$(YELLOW)$@$(GREEN) successfully generated\n"

$(BUILD_DIR):
	@ mkdir $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES)
	@ printf "$(DEFAULT)$< $(BLUE)->$(GREEN) $@$(DEFAULT)\n"
	@ $(CC) -c $<				\
	  -I./$(INCLUDE_DIR)		\
	  -I./$(MLX42_INCLUDE_DIR)	\
	  -I./$(LIBFT_INCLUDE_DIR)	\
	  -o $@						\
	  $(CC_FLAGS)

clean: clean_MLX clean_libft
	@ rm -rf $(BUILD_DIR)

fclean: fclean_MLX fclean_libft clean
	@ rm -rf $(NAME)

re: fclean all

$(LIBFT_LIB): $(LIBFT_DIR)
	@ make -s -C $(LIBFT_DIR)

$(MLX42_LIB): $(MLX42_DIR)
	@ cd $(MLX42_DIR) &&		\
	  cmake -B build &&			\
	  cmake --build build -j4

clean_libft: $(LIBFT_DIR)
	@ make -s -C $(LIBFT_DIR) clean

clean_MLX: $(MLX42_DIR)
	@ if [ -d $(MLX42_BUILD_DIR) ]; then				\
		find $(MLX42_BUILD_DIR) -mindepth 1 !			\
		-name '$(MLX42_LIB_NAME)' -exec rm -rf {} +;	\
	  fi

fclean_libft: $(LIBFT_DIR)
	@ make -s -C $(LIBFT_DIR) fclean

fclean_MLX: $(MLX42_DIR)
	@ rm -rf $(MLX42_BUILD_DIR)

clear_MLX:
	@ rm -rf $(MLX42_DIR)

clear_libft:
	@ rm -rf $(LIBFT_DIR)

clear: clear_MLX clear_libft
	@ rm -rf fractol
