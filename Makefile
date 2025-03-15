# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apouesse <apouesse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/15 11:03:00 by apouesse          #+#    #+#              #
#    Updated: 2025/03/15 19:01:01 by apouesse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/bash

GREEN  = \033[1;32m
RED    = \033[1;31m
VIOLET = \033[1;35m
ORANGE = \033[38;5;208m
BLEU   = \033[1;34m
JAUNE  = \033[1;33m
ROSE   = \033[1;95m
RESET  = \033[0m
NAME = cub3D

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = mlx_linux
MLX = $(MLX_DIR)/libmlx.a $(MLX_DIR)/libmlx_Linux.a

INCLUDES_DIR = includes

SRCS = srcs/main.c \
	srcs/colors/colors.c \
	srcs/freeing/uninit_data.c \
	srcs/init_data/init_data.c \
	srcs/Inputs/inputs.c \
	srcs/Parsing/parsing.c \
	srcs/Raycasting/raycasting_1.c \
	srcs/Rendering/rendering.c \
	srcs/utils/mlx_utils/mlx_utils_1.c \
	srcs/utils/utils_1.c \

TOTAL = $(words $(SRCS))

OBJS = $(SRCS:.c=.o)
CFLAGS = -Werror -Wall -Wextra -g3
CC = cc

all : $(NAME)

%.o: %.c $(LIBFT)
	@$(CC) $(CFLAGS) -I/include -I/libft -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME) : $(LIBFT) $(MLX) $(OBJS)
	@compiled=0; \
	total=$(TOTAL); \
	width=20; \
	for f in $(SRCS); do \
	  obj=$$(echo $$f | sed 's/\.c$$/.o/'); \
	  $(CC) $(CFLAGS) -I$(INCLUDES_DIR) -c $$f -o $$obj; \
	  compiled=$$((compiled+1)); \
	  percent=$$((compiled*100/total)); \
	  bar=""; \
	  for i in $$(seq 1 $$width); do \
	    if [ $$i -le $$((percent*width/100)) ]; then \
	      bar="$$bar~"; \
	    else \
	      bar="$$bar "; \
	    fi; \
	  done; \
	  text=$$(printf "%3d%%" $$percent); \
	  pos=$$(( (width - $${#text}) / 2 )); \
	  new_bar=$${bar:0:$$pos}$${text}$${bar:$$((pos + $${#text}))}; \
	  printf "\rCompilation en cours: ⏳[%s]⏳" "$$new_bar"; \
	  sleep 0.1; \
	done;
	@$(CC) $(CFLAGS) -I/include -I/libft $(OBJS) -Llibft -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) && \
	echo -e "\n$(GREEN)🔥Compilation done!🔥$(RESET)" || \
	{ echo -e "\n$(RED)Compilation failed!$(RESET)"; exit 1; }

$(LIBFT) :
	@$(MAKE) -s -C $(LIBFT_DIR) bonus

$(MLX) :
	@$(MAKE) -s -C $(MLX_DIR)

clean :
	@rm -rf $(OBJS)
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(MAKE) -s -C $(MLX_DIR) clean
	@echo -e "$(JAUNE)​🧼🧼 OBJS cleaned all! 🧼​🧼$(RESET)"

fclean : clean
	@rm -rf $(OBJS) $(NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@$(MAKE) -s -C $(MLX_DIR) clean
	@echo -e "$(VIOLET)​🧼​🧼​🧼🧼 Successfully cleaned all! 🧼​​🧼​​🧼​🧼$(RESET)"

re : fclean $(NAME)

.PHONY: all clean fclean re