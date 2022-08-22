cmake_minimum_required(VERSION 3.19)

project(list-all C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")

add_executable(list-all src/main.c)

install(TARGETS list-all
        RUNTIME
        DESTINATION /usr/local/bin/)
