cmake_minimum_required(VERSION 3.23)
project(opensr)

set(CMAKE_CXX_STANDARD 17)

if (MSVC)
    add_compile_options(/std:c++17)
    string(APPEND CMAKE_CXX_FLAGS " /EHsc")
endif()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fexceptions")
find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)
file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# todo: refactor to modules
add_executable(opensr main.cpp Graphics/ResourceLoader.cpp Graphics/ResourceLoader.h Logic/GameObject.cpp Logic/GameObject.h Logic/Galaxy.cpp Logic/Galaxy.h)
target_link_libraries(opensr sfml-system sfml-window sfml-graphics sfml-network sfml-audio)