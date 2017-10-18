# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atyrode <atyrode@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/30 18:19:00 by atyrode           #+#    #+#              #
#    Updated: 2017/10/18 10:16:29 by atyrode          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf

CC = gcc

FLAGS = -g -Wall -Wextra -Werror 

SRC = srcs/ft_printf.c

MINI_LIB = 	srcs/mini_lib/ft_atoi.c \
			srcs/mini_lib/ft_isdigit.c \
			srcs/mini_lib/ft_strchr.c \
			srcs/mini_lib/ft_strlen.c \
			srcs/mini_lib/ft_strsub.c \
			srcs/mini_lib/ft_strchrn.c \
			srcs/mini_lib/ft_putnbr.c \
			srcs/mini_lib/ft_putchar.c \
			srcs/mini_lib/ft_putstr.c

O_FILES = $(SRC:.c=.o)
O_FILES_LIB = $(MINI_LIB:.c=.o)

.PHONY: clean fclean re all cleanp clean_libft fclean fcleanp fclean_libft rep \
	re_libft make_libft

all: $(NAME)

$(NAME): $(O_FILES) $(O_FILES_LIB)
	$(CC) $(FLAGS) $(O_FILES) $(O_FILES_LIB) -o $(NAME)
	make clean

%.o:%.c includes/ft_printf.h
	$(CC) $(CC_FLAGS) -c -o $@ $<

clean: cleanp

cleanp:
	rm -rf $(O_FILES) $(O_FILES_LIB)

fclean: fcleanp

fcleanp: cleanp
	rm -rf $(NAME)

re: fclean all

rep: fcleanp all
