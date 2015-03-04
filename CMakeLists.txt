project(quark)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)

add_library(${PROJECT_NAME} STATIC ${SRC_LIST})
#add_executable(${PROJECT_NAME} ${SRC_LIST})

#list( APPEND CMAKE_CXX_FLAGS "-std=c++11" )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# include directories
set(INC_DIRS "")
# libraries
set(LIBS "")

# search for SDL
include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2_MIXER REQUIRED SDL2_mixer)
pkg_search_module(SDL2_IMAGE REQUIRED SDL2_image)
pkg_search_module(OPENGL REQUIRED gl glesv2)

set(LIBS ${LIBS} ${SDL2_LIBRARIES} ${SDL2_MIXER_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${OPENGL_LIBRARIES})
set(INC_DIRS ${INC_DIRS} ${SDL2_INCLUDE_DIRS} ${SDL2_MIXER_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${OPENGL_LIBRARIES})

# if there's possibility to add SDLMain, do it...
if(SDLMAIN_LIBRARY)
    set(LIBS ${LIBS} ${SDLMAIN_LIBRARY})
endif(SDLMAIN_LIBRARY)

include_directories(${INC_DIRS})
target_link_libraries(${PROJECT_NAME} ${LIBS})

install(TARGETS ${PROJECT_NAME} DESTINATION /usr/lib)
file(GLOB HEADERS . "*.h")
install(FILES ${HEADERS} DESTINATION ${CMAKE_INSTALL_PREFIX}/include/quark/)
install(FILES quark.pc DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/pkgconfig)
