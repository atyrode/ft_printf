# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atyrode <atyrode@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/30 18:19:00 by atyrode           #+#    #+#              #
#    Updated: 2017/10/17 18:34:38 by atyrode          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c

MINI_LIB =

O_FILES = $(SRC:.c=.o)

.PHONY: clean fclean re all cleanp clean_libft fclean fcleanp fclean_libft rep \
	re_libft make_libft

all: make_libft $(NAME)

make_libft:
    make -C libft

$(NAME): $(O_FILES)
	$(CC) $(FLAGS) $(O_FILES) -o $(NAME) $(LIBFT_L)
    make clean

%.o:%.c includes/ft_printf.h
    $(CC) $(CC_FLAGS) -c -o $@ $< $(LIBFT_I)

clean: cleanp clean_libft

cleanp:
    rm -rf $(O_FILES)

clean_libft:
    make -C libft clean

fclean: fclean_libft fcleanp

fcleanp: cleanp
	rm -rf $(NAME)

fclean_libft:
	make -C libft fclean

re: fclean all

rep: fcleanp all

re_libft:
    make -C libft re
