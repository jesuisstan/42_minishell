NAME     = minishell

SRCS     = ./src/main.c \
           ./src/signals/ms_signals_interactive_shell.c \
           ./src/signals/ms_signals_non_interactive_shell.c \
           ./src/builtins/ms_cd.c \
           ./src/builtins/ms_cd_utils.c \
           ./src/builtins/ms_echo.c \
           ./src/builtins/ms_env.c \
           ./src/builtins/ms_exit.c \
           ./src/builtins/ms_unset.c \
           ./src/builtins/ms_export.c \
           ./src/builtins/ms_pwd.c \
           ./src/builtins/ms_export_utils.c \
           ./src/utils/ms_arglist_to_array.c \
           ./src/utils/ms_arrlen.c \
           ./src/utils/ms_envp_l_utils.c \
           ./src/utils/ms_envplist_to_array.c \
           ./src/utils/ms_envp_m_utils.c \
           ./src/utils/ms_lstfree_arg.c \
           ./src/utils/ms_lstfree_cmd.c \
           ./src/utils/ms_lstfree_rdr.c \
           ./src/utils/ms_malloc_x.c \
           ./src/utils/ms_return_error.c \
           ./src/utils/ms_update_shlvl.c \
           ./src/parser/ms_check_redirect.c \
           ./src/parser/ms_clone_envp.c \
           ./src/parser/ms_extract_redirects.c \
           ./src/parser/ms_get_commands.c \
           ./src/parser/ms_handle_digital_key.c \
           ./src/parser/ms_manage_dollar.c \
           ./src/parser/ms_manage_whitespaces.c \
           ./src/parser/ms_parse.c \
           ./src/parser/ms_protoparse.c \
           ./src/parser/ms_split_line.c \
           ./src/parser/ms_purify_argument.c \
           ./src/parser/ms_set_redirect_flags.c \
           ./src/commands/ms_builtin.c \
           ./src/commands/ms_command.c \
           ./src/commands/ms_dups.c \
           ./src/commands/ms_error.c \
           ./src/commands/ms_path.c \
           ./src/commands/ms_pipe.c \
           ./src/commands/ms_redirects.c

OBJS     = $(SRCS:.c=.o)

HEADERS  = -I./inc/ -I.src/libft/inc/

CC       = gcc

RM       = rm -rfv

OS       = $(shell uname -s)

ifeq ($(OS), Darwin)
	CFLAGS = -I ~/.brew/opt/readline/include/
	RDL = -lreadline -L ~/.brew/opt/readline/lib
else
	CFLAGS = -I /usr/include/readline/
	RDL = -lreadline
endif

LIBS     = ./src/libft/libft.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

$(NAME): $(OBJS) ./inc/minishell.h ./inc/minishell_struct.h ./src/libft/inc/libft.h
	cd ./src/libft/ && $(MAKE)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) $(HEADERS) $(RDL)

clean:
	$(MAKE) clean -C ./src/libft/
	$(RM) $(OBJS)
	@echo "\033[36;1m\nCleaning succeed\n\033[0m"

fclean: clean
	$(MAKE) fclean -C ./src/libft/
	$(RM) $(NAME)
	@echo "\033[32;1m\nAll created files were deleted\n\033[0m"

re: fclean $(NAME)
	@echo "\033[35;1m\nRemake done\n\033[0m"

.PHONY: all clean fclean re
