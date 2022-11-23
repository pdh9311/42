# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donpark <donpark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/06 12:25:25 by donpark           #+#    #+#              #
#    Updated: 2021/05/06 12:25:30 by donpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRCS = ft_printf.c 	check_info.c chg_to_hex.c \
	apply_to_char.c apply_to_int.c \
	print_int.c print_char.c
OBJS = $(SRCS:.c=.o)

LIBFT = libft
LIBFT_LIB = libft.a

.PHONY : all clean fclean re

all : $(NAME)

.c.o :
	$(CC) $(CFLAGS) -c $? -o $@

$(NAME) : $(OBJS)
	make all -C $(LIBFT)
	cp ./$(LIBFT)/$(LIBFT_LIB) ./$(NAME)
	$(AR) $@ $^

clean :
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re : fclean all

