# 42_minishell
## Foreword
This is one of the Ecole 42 common core projects.\
It is about create a simple shell (bash).\
The project is written with holly C language and \
provides good understanding of processes and file descriptors.

## Description
The following containers implemented and turned in the necessary `<container>.hpp` files with
a `Makefile`:
- vector
- map
- stack
- set (Red-Black tree)

Also implemented:
- std::iterator_traits
- std::reverse_iterator
- std::enable_if
- std::is_integral
- std::equal and/or std::lexicographical_compare
- std::pair
- std::make_pair

Full project description you can find in `en.subject.pdf`

## Requirements
- installed clang++
- installed Makefile

## How to use
In project directory:
1. Run the `test.sh` to difference between STL and my containers performance\
(the content of performed test can be checked in `main_ft.cpp` and `main_stl.cpp` files).
2. Run `make fclean` to delete all created files.
