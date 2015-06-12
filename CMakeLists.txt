cmake_minimum_required(VERSION 3.0)
project(bgj09)

#find_package(library)

add_definitions("-g -Wall -Wextra -pedantic -Werror -std=c++14")

if(${EMSCRIPTEN})
    add_definitions("-Oz -s USE_SDL=2 -o index.html")
else()
    include(FindPkgConfig)
    pkg_search_module(SDL2 REQUIRED sdl2)
    pkg_search_module(SDL2_IMAGE REQUIRED SDL2_image)
    pkg_search_module(SDL2_MIXER REQUIRED SDL2_mixer)
endif()

file(GLOB sources src/*.cpp)

include_directories(
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_IMAGE_INCLUDE_DIRS}
)

add_subdirectory(entityx)

add_executable(bgj09 ${sources})

target_link_libraries(bgj09
    ${SDL2_LIBRARIES}
    ${SDL2_IMAGE_LIBRARIES}
    entityx
)
