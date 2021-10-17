cmake_minimum_required(VERSION 3.14)

project(game VERSION 0.10)

set(SFML_DIR libs/SFML-2.5.1/lib/cmake/SFML)
set(SFML_ROOT_DIR libs/SFML-2.5.1)


set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2.5.1 COMPONENTS system window graphics audio network REQUIRED)

file(GLOB SRCF src/**/*.cpp)
add_executable(game src/main.cpp ${SRCF})

if(SFML_FOUND)
    message("SFML_DIR: ${SFML_DIR}")
    message("SFML_LIBRARY_DIR: ${SFML_LIBRARY_DIR}")
    message("SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message("SFML_ROOT_DIR: ${SFML_ROOT_DIR}")

    include_directories(${SFML_ROOT_DIR}/include)
    # link_directories(${SFML_ROOT_DIR}/lib)
    target_link_libraries(game optimized sfml-graphics debug sfml-graphics-d 
                                optimized sfml-window debug sfml-window-d 
                                optimized sfml-system debug sfml-system-d 
                                optimized sfml-audio debug sfml-audio-d     )
endif(SFML_FOUND)

if(NOT SFML_STATIC_LIBRARIES)
    # copy dynamic libraries to build directory
    message(STATUS "Static Link Off: Using SFML DLLs/SO for Dynamic Linking Instead")
    file(GLOB SFML_DLLS ${SFML_ROOT_DIR}/bin/*.dll )
    file(COPY ${SFML_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()

