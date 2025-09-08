# Minimum CMake version
cmake_minimum_required(VERSION 3.20.0)

# Locate the Zephyr RTOS source
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

# Name the project
project(
    blink
    LANGUAGES C
)

add_library(
    print
    STATIC
    src/print.c
)

target_include_directories(
    print
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_sources(
    app
    PRIVATE
    src/main.c
)

target_link_libraries(
    app
    PRIVATE
    print
)