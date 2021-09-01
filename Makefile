# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaren <acaren@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/20 17:33:58 by acaren            #+#    #+#              #
#    Updated: 2021/08/31 22:10:09 by acaren           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= 	minishell

SRCS			=	./src/main.c	./src/ms_print_envp.c	./src/ms_return_error.c \

OBJS			=	$(SRCS:.c=.o)

HEADERS			=	./inc/minishell.h

CC				=	gcc

RM				=	rm -rfv

CFLAGS			=	-Wall -Wextra -Werror -I$(HEADERS)

LIBS			=	./src/libft/libft.a

all:			$(NAME)

$(OBJS):		$(HEADERS)

$(NAME):		$(OBJS)
				cd ./src/libft/ && $(MAKE)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

clean:
				$(MAKE) clean -C ./src/libft/
				$(RM) $(OBJS)
				@echo "\033[36;1m\nCleaning succeed\n\033[0m"

fclean:			clean
				$(MAKE) fclean -C ./src/libft/
				$(RM) $(NAME)
				@echo "\033[32;1m\nAll created files were deleted\n\033[0m"

re:				fclean $(NAME)
				@echo "\033[35;1m\nRemake done\n\033[0m"

.PHONY:			all clean fclean re
