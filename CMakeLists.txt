project(quark)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)

add_library(${PROJECT_NAME} STATIC ${SRC_LIST})

list( APPEND CMAKE_CXX_FLAGS "-std=c++0x" )

# include directories
set(INC_DIRS "")
# libraries
set(LIBS "")

# search for SDL
include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)
set(LIBS ${LIBS} ${SDL2_LIBRARIES})
set(INC_DIRS ${INC_DIRS} ${SDL2_INCLUDE_DIRS})

# if there's possibility to add SDLMain, do it...
if(SDLMAIN_LIBRARY)
    set(LIBS ${LIBS} ${SDLMAIN_LIBRARY})
endif(SDLMAIN_LIBRARY)

include_directories(${INC_DIRS})
target_link_libraries(${PROJECT_NAME} ${LIBS})

