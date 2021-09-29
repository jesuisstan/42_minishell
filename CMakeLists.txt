cmake_minimum_required(VERSION 3.20)
project(minishell C)

set(CMAKE_C_STANDARD 99)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/libft/)
add_executable(minishell  src/commands/ms_command.c src/commands/ms_path.c src/commands/ms_builtin.c src/utils/ms_arrlen.c src/parser/ms_clone_envp.c src/utils/ms_find_envp.c src/utils/ms_malloc_x.c src/commands/ms_path.c)
target_link_libraries (minishell ${CMAKE_CURRENT_SOURCE_DIR}/src/libft/libft.a)


#ms_command.c mчs_path.c ../libft/libft.a ../parser/ms_clone_envp.c ../utils/*