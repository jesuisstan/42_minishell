NAME			= 	minishell

SRCS			=	./src/main.c \
					$(wildcard ./src/utils/*.c) \
					$(wildcard ./src/parser/*.c) \
					$(wildcard ./src/builtins/*.c) \
					$(wildcard ./src/commands/*.c)

OBJS			=	$(SRCS:.c=.o)

HEADERS			=	-I./inc/ -I.src/libft/inc/ -I ~/.brew/opt/readline/include/

CC				=	gcc

RM				=	rm -rfv

#CFLAGS			=	-Wall -Wextra -Werror

LIBS			=	./src/libft/libft.a
RDL				= -lreadline
RDL_MAC			= -lreadline -L ~/.brew/opt/readline/lib

all:			$(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) -c -g $< -o $@ $(HEADERS)

$(NAME):		$(OBJS)
				cd ./src/libft/ && $(MAKE)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) $(HEADERS) $(RDL_MAC)

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