cmake_minimum_required(VERSION 3.0)
project(bgj09)

#find_package(library)

add_definitions("-g -Wall -Wextra -pedantic -Werror -std=c++14 -Wno-unused-parameter")

file(GLOB sources src/*.cpp)

add_executable(bgj09 ${sources})

if(${EMSCRIPTEN})
    set(CROSS_COMPILING ON)
    add_definitions("-Oz -s USE_SDL=2 -Wno-warn-absolute-paths")
    set(CMAKE_CXX_LINK_FLAGS "-s USE_SDL=2 -o index.html")
    #set_target_properties(bgj09 PROPERTIES CMAKE_EXE_LINKER_FLAGS "-o index.html")
else()
    include(FindPkgConfig)
    pkg_check_modules(SDL2 REQUIRED sdl2 SDL2_gfx SDL2_image SDL2_mixer SDL2_ttf)
endif()

include_directories(
    ${SDL2_INCLUDE_DIRS}
)

set(ENTITYX_BUILD_TESTING false CACHE BOOL "")
add_subdirectory(entityx)

target_link_libraries(bgj09
    ${SDL2_LIBRARIES}
    entityx
)
