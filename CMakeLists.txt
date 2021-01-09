cmake_minimum_required(VERSION 3.17)
project(lvl2_ft_printf C)

set(CMAKE_C_STANDARD 99)
#SET(CMAKE_C_FLAGS "-Wall -Werror -Wextra")

#add_executable(lvl2_ft_printf main.c)
file(GLOB SOURCE_FILES *.c *.h)

add_executable(lvl2_ft_printf ${SOURCE_FILES})