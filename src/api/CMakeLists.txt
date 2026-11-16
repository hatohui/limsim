add_library(api INTERFACE)
target_include_directories(api INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(api INTERFACE core sim save)

# TODO: switch to SHARED and add src/ once the API is implemented
