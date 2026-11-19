add_library(core INTERFACE
        include/hatogin/core/tick.hpp)
target_include_directories(core INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)