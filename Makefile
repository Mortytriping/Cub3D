# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apouesse <apouesse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/15 11:03:00 by apouesse          #+#    #+#              #
#    Updated: 2025/03/15 11:16:24 by apouesse         ###   ########.fr        #
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

INCLUDES_DIR = includes

SRCS_DIR = srcs/
SRCS = $(SRCS_DIR)main.c 

TOTAL = $(words $(SRCS))

OBJS = $(SRCS:.c=.o)
CFLAGS = -Werror -Wall -Wextra -g3
CC = cc

all : $(NAME)

%.o: %.c $(LIBFT)
	@$(CC) $(CFLAGS) -I/include -I/libft -c $< -o $@

$(NAME) : $(LIBFT) $(OBJS)
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
	@$(CC) $(CFLAGS) -I/include -I/libft $(OBJS) -Llibft -lft -o $(NAME) -lreadline; \
	echo -e "\n$(GREEN)🔥Compilation done!🔥$(RESET)"

$(LIBFT) :
	@$(MAKE) -s -C $(LIBFT_DIR) bonus

clean :
	@rm -rf $(OBJS)
	@$(MAKE) -s -C $(LIBFT_DIR) clean

fclean : clean
	@rm -rf $(OBJS) $(NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	echo -e "$(RED)Successfully cleaned all!$(RESET)"

re : fclean $(NAME)

.PHONY: all clean fclean re