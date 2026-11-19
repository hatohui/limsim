cmake_minimum_required(VERSION 3.25)
project(hatogin LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(HATOGIN_BUILD_NET "Build co-op commands" OFF)
option(HATOGIN_BUILD_TESTS "Build unit and integration tests" ON)

if(HATOGIN_BUILD_TESTS)
  enable_testing()
  include(cmake/doctest.cmake)
endif()

add_subdirectory(src)
