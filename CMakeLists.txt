cmake_minimum_required(VERSION 3.17)
project(lvl2_ft_printf C)

set(CMAKE_C_STANDARD 99)

#add_executable(lvl2_ft_printf main.c)
file(GLOB SOURCE_FILES *.c *.h libft/*.c libft/*.h)

add_executable(lvl2_ft_printf ${SOURCE_FILES})