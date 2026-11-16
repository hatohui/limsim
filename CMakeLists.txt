cmake_minimum_required(VERSION 3.25)
project(limsim LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(LIMSIM_BUILD_NET "Build optional co-op command sync library" OFF)
option(LIMSIM_BUILD_TESTS "Build unit and integration tests" ON)

if(LIMSIM_BUILD_TESTS)
  enable_testing()
  include(cmake/doctest.cmake)
endif()

add_subdirectory(src)
