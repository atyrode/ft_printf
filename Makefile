# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atyrode <atyrode@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/30 18:19:00 by atyrode           #+#    #+#              #
#    Updated: 2017/10/19 18:20:43 by atyrode          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf

CC = gcc

#FLAGS = -Wall -Wextra -Werror

SRC = srcs/ft_printf.c

MINI_LIB = 	srcs/mini_lib/ft_atoi.c \
			srcs/mini_lib/ft_isdigit.c \
			srcs/mini_lib/ft_strchr.c \
			srcs/mini_lib/ft_strlen.c \
			srcs/mini_lib/ft_strsub.c \
			srcs/mini_lib/ft_strchrn.c \
			srcs/mini_lib/ft_putnbr.c \
			srcs/mini_lib/ft_putchar.c \
			srcs/mini_lib/ft_putstr.c \
			srcs/mini_lib/ft_search.c \
			srcs/mini_lib/ft_itoa_base.c \
			srcs/mini_lib/ft_tolower.c \
			srcs/mini_lib/ft_strnew.c \
			srcs/mini_lib/ft_memset.c \
			srcs/mini_lib/ft_memalloc.c \
			srcs/mini_lib/ft_itoa.c \
			srcs/mini_lib/ft_strdup.c \
			srcs/mini_lib/ft_strjoin.c \
			srcs/mini_lib/ft_strlwr.c

O_FILES = $(SRC:.c=.o)
O_FILES_LIB = $(MINI_LIB:.c=.o)

.PHONY: clean fclean re all cleanp clean_libft fclean fcleanp fclean_libft rep \
	re_libft make_libft

all: $(NAME)

$(NAME): $(O_FILES) $(O_FILES_LIB)
	ar rc libftprintf.a $(O_FILES) $(O_FILES_LIB)

%.o:%.c includes/ft_printf.h
	$(CC) -g $(FLAGS) -c -o $@ $< $(MAIN_MACRO)

clean: cleanp

main: fclean set_main_flags make_main

make_main: $(O_FILES) $(O_FILES_LIB)
	$(CC) -g $(FLAGS) $(O_FILES) $(O_FILES_LIB) -o $(NAME)
	make clean

set_main_flags:
	$(eval MAIN_MACRO = -DMAIN)

cleanp:
	rm -rf $(O_FILES) $(O_FILES_LIB)

fclean: fcleanp

fcleanp: cleanp
	rm -rf $(NAME)

re: fclean all

rep: fcleanp all
