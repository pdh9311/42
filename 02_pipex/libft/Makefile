# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donpark <donpark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/19 12:20:42 by donpark           #+#    #+#              #
#    Updated: 2021/06/19 12:20:43 by donpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./

AR = ar rcs

SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
	ft_calloc.c ft_strdup.c \
	ft_substr.c ft_strjoin.c ft_strtrim.c \
	ft_split.c ft_itoa.c ft_strmapi.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_realloc.c get_next_line.c \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
	ft_lstiter.c ft_lstmap.c

OBJS = $(SRCS:.c=.o)

.PHONY : all clean fclean re

all : $(NAME)

.c.o :
	$(CC) $(CFLAGS) -c $? -o $@

$(NAME) : $(OBJS)
	$(AR) $@ $^
	ranlib $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

