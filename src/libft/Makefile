# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaren <acaren@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/22 23:15:52 by acaren            #+#    #+#              #
#    Updated: 2021/09/01 15:57:22 by acaren           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= 	libft.a

SRCS			=	./src/ft_strlen.c		./src/ft_strncmp.c		./src/ft_strlcpy.c \
					./src/ft_strchr.c		./src/ft_strrchr.c		./src/ft_isdigit.c \
					./src/ft_isalpha.c		./src/ft_isprint.c		./src/ft_isalnum.c \
					./src/ft_isascii.c		./src/ft_putchar_fd.c	./src/ft_putstr_fd.c \
					./src/ft_putendl_fd.c	./src/ft_memcmp.c		./src/ft_memcpy.c \
					./src/ft_memset.c		./src/ft_memchr.c		./src/ft_memccpy.c \
					./src/ft_memmove.c		./src/ft_bzero.c		./src/ft_tolower.c \
					./src/ft_toupper.c		./src/ft_putnbr_fd.c	./src/ft_strlcat.c \
					./src/ft_strdup.c		./src/ft_calloc.c		./src/ft_atoi.c \
					./src/ft_strmapi.c		./src/ft_substr.c		./src/ft_strjoin.c \
					./src/ft_strnstr.c		./src/ft_itoa.c			./src/ft_strtrim.c \
					./src/ft_split.c		./src/ft_putnchar.c		./src/ft_putnbr_uns_fd.c \
					./src/ft_strrev.c		./src/ft_free_array.c	./src/ft_malloc_int_array.c \
					./src/get_next_line.c \
															
HEADERS			=	./inc/libft.h

OBJS			= 	$(SRCS:.c=.o)

CC				= 	gcc
RM				= 	rm -f
CFLAGS			= 	-Wall -Wextra -Werror

all:			$(NAME)

$(NAME):		$(OBJS) $(HEADERS)
				ar rcs $(NAME) $?

clean:
				$(RM) $(OBJS) $(OBJS_BONUS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re