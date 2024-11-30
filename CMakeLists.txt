cmake_minimum_required(VERSION 3.15)
project(Pim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")

find_package(Curses REQUIRED)

add_subdirectory(src)
#add_subdirectory(tests)

install(TARGETS pim DESTINATION bin)
