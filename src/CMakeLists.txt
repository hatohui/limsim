add_subdirectory(libs/core)
add_subdirectory(libs/sim)
add_subdirectory(libs/save)

if(HATOGIN_BUILD_NET)
  add_subdirectory(libs/net)
endif()

add_subdirectory(api)
add_subdirectory(apps/cli)
