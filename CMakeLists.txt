cmake_minimum_required(VERSION 3.22)
project(Phisics2D LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include_directories(inc)

file(GLOB SOURCES
    inc/*.hpp
    src/*.cpp
)

add_executable(main ${SOURCES})
target_link_libraries(main PRIVATE sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
target_compile_features(main PRIVATE cxx_std_17)

add_custom_target(copy_assets ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/assets ${CMAKE_CURRENT_BINARY_DIR}/assets
)
