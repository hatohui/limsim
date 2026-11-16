# Fetches doctest and provides limsim_add_test(<name> SOURCES ... LIBS ...).
include(FetchContent)
FetchContent_Declare(
  doctest
  GIT_REPOSITORY https://github.com/doctest/doctest.git
  GIT_TAG v2.4.12
  GIT_SHALLOW TRUE
)
set(DOCTEST_NO_INSTALL ON CACHE BOOL "" FORCE)
# doctest declares an old cmake_minimum_required; raise it for doctest only so
# CMake 4 configures it without deprecation warnings.
set(CMAKE_POLICY_VERSION_MINIMUM 3.10)
FetchContent_MakeAvailable(doctest)
unset(CMAKE_POLICY_VERSION_MINIMUM)

function(limsim_add_test name)
  cmake_parse_arguments(ARG "" "" "SOURCES;LIBS" ${ARGN})
  add_executable(${name} ${ARG_SOURCES})
  target_link_libraries(${name} PRIVATE doctest::doctest_with_main ${ARG_LIBS})
  add_test(NAME ${name} COMMAND ${name})
endfunction()
