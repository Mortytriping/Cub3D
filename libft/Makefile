# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaroukh <abaroukh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 18:39:12 by abaroukh          #+#    #+#              #
#    Updated: 2024/11/29 16:59:24 by abaroukh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra
LIBFT_SOURCES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c \
ft_toupper.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_striteri.c ft_putnbr_fd.c

PRINTF_DIR = printf
PRINTF_SOURCES = $(PRINTF_DIR)/ft_hexa_down.c $(PRINTF_DIR)/ft_hexa_up.c $(PRINTF_DIR)/ft_print_address.c \
$(PRINTF_DIR)/ft_print_uint.c $(PRINTF_DIR)/ft_printf.c $(PRINTF_DIR)/ft_putchar.c $(PRINTF_DIR)/ft_putnbr.c \
$(PRINTF_DIR)/ft_putstr.c

GNL_DIR = get_next_line
GNL_SOURCES = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c

SOURCES = $(LIBFT_SOURCES) $(PRINTF_SOURCES) $(GNL_SOURCES)

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
