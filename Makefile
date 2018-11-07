# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbixby <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/01 14:08:17 by bbixby            #+#    #+#              #
#    Updated: 2018/11/01 14:08:19 by bbixby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LNAME = libft.a
LFILES = ./libft/ft_memset.c \
./libft/ft_bzero.c \
./libft/ft_memcpy.c \
./libft/ft_memccpy.c \
./libft/ft_memmove.c \
./libft/ft_memchr.c \
./libft/ft_memcmp.c \
./libft/ft_strlen.c \
./libft/ft_strdup.c \
./libft/ft_strcpy.c \
./libft/ft_strncpy.c \
./libft/ft_strcat.c \
./libft/ft_strncat.c \
./libft/ft_strlcat.c \
./libft/ft_strchr.c \
./libft/ft_strrchr.c \
./libft/ft_strstr.c \
./libft/ft_strnstr.c \
./libft/ft_strcmp.c \
./libft/ft_strncmp.c \
./libft/ft_atoi.c \
./libft/ft_isalpha.c \
./libft/ft_isdigit.c \
./libft/ft_isalnum.c \
./libft/ft_isascii.c \
./libft/ft_isprint.c \
./libft/ft_toupper.c \
./libft/ft_tolower.c \
./libft/ft_memalloc.c \
./libft/ft_memdel.c \
./libft/ft_strnew.c \
./libft/ft_strdel.c \
./libft/ft_strclr.c \
./libft/ft_striter.c \
./libft/ft_striteri.c \
./libft/ft_strmap.c \
./libft/ft_strmapi.c \
./libft/ft_strequ.c \
./libft/ft_strnequ.c \
./libft/ft_strsub.c \
./libft/ft_strjoin.c \
./libft/ft_strtrim.c \
./libft/ft_strsplit.c \
./libft/ft_itoa.c \
./libft/ft_putchar.c \
./libft/ft_putstr.c \
./libft/ft_putendl.c \
./libft/ft_putnbr.c \
./libft/ft_putchar_fd.c \
./libft/ft_putstr_fd.c \
./libft/ft_putendl_fd.c \
./libft/ft_putnbr_fd.c \
./libft/ft_lstnew.c \
./libft/ft_lstdelone.c \
./libft/ft_lstdel.c \
./libft/ft_lstadd.c \
./libft/ft_lstiter.c \
./libft/ft_lstmap.c
LOFILES = ./ft_memset.o \
./ft_bzero.o \
./ft_memcpy.o \
./ft_memccpy.o \
./ft_memmove.o \
./ft_memchr.o \
./ft_memcmp.o \
./ft_strlen.o \
./ft_strdup.o \
./ft_strcpy.o \
./ft_strncpy.o \
./ft_strcat.o \
./ft_strncat.o \
./ft_strlcat.o \
./ft_strchr.o \
./ft_strrchr.o \
./ft_strstr.o \
./ft_strnstr.o \
./ft_strcmp.o \
./ft_strncmp.o \
./ft_atoi.o \
./ft_isalpha.o \
./ft_isdigit.o \
./ft_isalnum.o \
./ft_isascii.o \
./ft_isprint.o \
./ft_toupper.o \
./ft_tolower.o \
./ft_memalloc.o \
./ft_memdel.o \
./ft_strnew.o \
./ft_strdel.o \
./ft_strclr.o \
./ft_striter.o \
./ft_striteri.o \
./ft_strmap.o \
./ft_strmapi.o \
./ft_strequ.o \
./ft_strnequ.o \
./ft_strsub.o \
./ft_strjoin.o \
./ft_strtrim.o \
./ft_strsplit.o \
./ft_itoa.o \
./ft_putchar.o \
./ft_putstr.o \
./ft_putendl.o \
./ft_putnbr.o \
./ft_putchar_fd.o \
./ft_putstr_fd.o \
./ft_putendl_fd.o \
./ft_putnbr_fd.o \
./ft_lstnew.o \
./ft_lstdelone.o \
./ft_lstdel.o \
./ft_lstadd.o \
./ft_lstiter.o \
./ft_lstmap.o
LHEADER = libft/libft.h

NAME = fillit
CFLAGS = -Wall -Werror -Wextra
RM = /bin/rm -rf
HEADER = fillit.h
CFILES = ./src/fillit.c ./src/verification.c ./src/solver.c ./src/solver2.c ./src/helpers.c ./src/queue.c ./src/free.c
OFILES = ./fillit.o ./verification.o ./solver.o ./solver2.o ./helpers.o ./queue.o ./free.o

all: $(NAME)

$(NAME): $(LOFILES)
	ar rc $(LNAME) $(LOFILES)
	ranlib $(LNAME)
	gcc $(CFLAGS) -I=$(HEADER) -o $(NAME) $(CFILES) $(LNAME)
	# gcc -g -fsanitize=address -I=$(HEADER) -o $(NAME) $(CFILES) $(LNAME)
	# gcc $(CFLAGS) -I=$(HEADER) -o $(NAME) $(CFILES) $(LNAME)

$(LOFILES): $(LFILES)
	gcc -c $(CFLAGS) -I=$(LHEADER) $(LFILES)

clean:
	$(RM) $(OFILES) $(LOFILES)

fclean: clean
	$(RM) $(NAME) $(LNAME)

re: fclean all

.PHONY: clean fclean all re

