cmake_minimum_required(VERSION 3.13)
project(dining_philosophers)
set(THREAD_SANITIZER_FLAG "-fsanitize=thread")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set (SRC_LIST
    philosopher.cpp
    main.cpp)
include_directories(.)
add_library(${PROJECT_NAME}-lib ${SRC_LIST})
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)
target_link_libraries(${PROJECT_NAME} pthread)
