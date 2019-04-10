cmake_minimum_required(VERSION 3.13)
project(dining_philosophers)
set(THREAD_SANITIZER_FLAG "-fsanitize=thread")
set (SRC_LIST
    philosopher.cpp
    main.cpp)
include_directories(.)
add_library(${PROJECT_NAME}-lib ${SRC_LIST})
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)
