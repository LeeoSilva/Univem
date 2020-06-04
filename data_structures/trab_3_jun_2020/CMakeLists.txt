cmake_minimum_required(VERSION 3.14)
project(filaBanco)

set(OPTION_BUILD "-j 8 -std=c++11 -g")
set(OPTION_BUILD "-W -Wall -Werror -Wextra") # For displaying debug information
SET(CMAKE_COLOR_MAKEFILE ON)

add_library(priorityQueue
    ./headers/priorityQueue.hpp
    ./src/priorityQueue.cpp
)

add_library(menu
    ./headers/menu.hpp
    ./src/menu.cpp
)

add_library(client
    ./headers/client.hpp
    ./src/client.cpp
)

add_executable(${PROJECT_NAME}
    ./src/main.cpp
)

target_link_libraries(${PROJECT_NAME} priorityQueue)
target_link_libraries(${PROJECT_NAME} menu)
target_link_libraries(${PROJECT_NAME} client)
