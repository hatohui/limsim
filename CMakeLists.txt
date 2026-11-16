cmake_minimum_required(VERSION 3.25)
project(limsim LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(LIMSIM_BUILD_NET "Build optional co-op command sync library" OFF)

add_subdirectory(src)
