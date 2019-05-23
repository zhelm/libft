# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zhelm <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/23 09:14:54 by zhelm             #+#    #+#              #
#    Updated: 2019/05/23 11:22:28 by zhelm            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c\
	ft_isprint.c\
	ft_strcat.c\
	ft_toupper.c\
	ft_memccpy.c\
	ft_strcpy.c\
	ft_bzero.c\
	ft_memchr.c\
	ft_strdup.c\
	ft_isalnum.c\
	ft_memcmp.c\
	ft_strlen.c\
	ft_isalpha.c\
	ft_memcpy.c\
	ft_strncat.c\
	ft_isascii.c\
	ft_memmove.c\
	ft_strncpy.c\
	ft_isdigit.c\
	ft_memset.c\
	ft_tolower.c


OBJ = ft_isalnum.o\
	ft_memchr.o\
	ft_strcpy.o\
	ft_toupper.o\
	ft_isalpha.o\
	ft_memcmp.o\
	ft_strdup.o\
	ft_isascii.o\
	ft_memcpy.o\
	ft_strlen.o\
	ft_isdigit.o\
	ft_memmove.o\
	ft_strncat.o\
	ft_atoi.o\
	ft_isprint.o\
	ft_memset.o\
	ft_strncpy.o\
	ft_bzero.o\
	ft_memccpy.o\
	ft_strcat.o\
	ft_tolower.o

all: $(NAME)

$(NAME): 
	gcc -Wall -Wextra -Werror -c $(SRCS)	
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean: 
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

