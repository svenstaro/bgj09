cmake_minimum_required(VERSION 3.0)
project(bgj09)

#find_package(library)

add_definitions("-g -Wall -Wextra -pedantic -Werror -std=c++14 -Wno-unused-parameter")

file(GLOB sources src/*.cpp)

add_executable(bgj09 ${sources})

if(${EMSCRIPTEN})
    set(CROSS_COMPILING ON)
    add_definitions("-Oz -s USE_SDL=2 -s USE_SDL_IMAGE=2 -Wno-warn-absolute-paths")
    set(CMAKE_CXX_LINK_FLAGS "-Oz -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s TOTAL_MEMORY=32000000 --preload-file ../res -o index.html")
else()
    add_definitions("-O0")
    include(FindPkgConfig)
    pkg_check_modules(SDL2 REQUIRED sdl2 SDL2_gfx SDL2_image SDL2_mixer SDL2_ttf)
endif()

set(ENTITYX_BUILD_TESTING false CACHE BOOL "")
add_subdirectory(entityx)

include_directories(
    ${SDL2_INCLUDE_DIRS}
    glm/
    strapon/
    entityx/
)

target_link_libraries(bgj09
    ${SDL2_LIBRARIES}
    entityx
)
