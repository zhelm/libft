# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zhelm <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/23 09:14:54 by zhelm             #+#    #+#              #
#    Updated: 2019/05/28 13:32:47 by zhelm            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c\
	ft_bzero.c\
	ft_isascii.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_memcpy.c\
	ft_memccpy.c\
	ft_memchr.c\
	ft_memmove.c\
	ft_memset.c\
	ft_memcmp.c\
	ft_strlen.c\
	ft_strdup.c\
	ft_strcpy.c\
	ft_strncpy.c\
	ft_strcat.c\
	ft_strncat.c\
	ft_strlcat.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strstr.c\
	ft_strnstr.c\
	ft_strcmp.c\
	ft_strncmp.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_memalloc.c\
	ft_memdel.c\
	ft_strnew.c\
	ft_strdel.c\
	ft_strclr.c\
	ft_strsub.c


OBJ = ft_atoi.o\
	ft_bzero.o\
	ft_isascii.o\
	ft_isalnum.o\
	ft_isalpha.o\
	ft_isdigit.o\
	ft_isprint.o\
	ft_memcpy.o\
	ft_memccpy.o\
	ft_memchr.o\
	ft_memmove.o\
	ft_memset.o\
	ft_memcmp.o\
	ft_strlen.o\
	ft_strdup.o\
	ft_strcpy.o\
	ft_strncpy.o\
	ft_strcat.o\
	ft_strncat.o\
	ft_strlcat.o\
	ft_strchr.o\
	ft_strrchr.o\
	ft_strstr.o\
	ft_strnstr.o\
	ft_strcmp.o\
	ft_strncmp.o\
	ft_tolower.o\
	ft_toupper.o\
	ft_memalloc.o\
	ft_memdel.o\
	ft_strnew.o\
	ft_strdel.o\
	ft_strclr.o\
	ft_strsub.o

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

