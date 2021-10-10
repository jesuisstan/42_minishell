cmake_minimum_required(VERSION 3.19.2)
project(minishell C)

set(CMAKE_C_STANDARD 99)
include_directories(/usr/include/readline)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/libft/)

FILE(GLOB SRC
       "src/main.c"
        "src/builtins/*.c"
        "src/utils/*.c"
        "src/commands/*.c"
        "src/parser/*.c")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall")
add_executable(minishell ${SRC})
target_link_libraries (minishell ${CMAKE_CURRENT_SOURCE_DIR}/src/libft/libft.a)
target_link_libraries (minishell readline)

#cmake_minimum_required(VERSION 3.20)
#project(minishell C)
#
#set(CMAKE_C_STANDARD 99)
#include_directories(/usr/include/readline)
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/libft/)
#
#FILE(GLOB SRC
#        "src/main.c"
#        "src/builtins/*.c"
#        "src/utils/*.c"
#        "src/commands/*.c"
#        "src/parser/*.c")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall")
#add_executable(minishell ${SRC} src/commands/ms_redirects.c)
#target_link_libraries (minishell ${CMAKE_CURRENT_SOURCE_DIR}/src/libft/libft.a)
#target_link_libraries (minishell readline)

#        src/commands/ms_pipe.c src/commands/ms_command.c src/commands/ms_path.c src/commands/ms_builtin.c \
#src/utils/ms_arrlen.c src/parser/ms_clone_envp.c src/utils/ms_find_envp.c src/utils/ms_malloc_x.c src/commands/ms_path.c src/minishell.c
