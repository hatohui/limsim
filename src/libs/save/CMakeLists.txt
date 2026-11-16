add_library(save INTERFACE)
target_include_directories(save INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(save INTERFACE core sim)
# TODO: switch to STATIC and list sources in src/ once code exists
