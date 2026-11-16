add_library(net INTERFACE)
target_include_directories(net INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(net INTERFACE core sim)
# TODO: switch to STATIC and list sources in src/ once code exists
