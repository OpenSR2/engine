cmake_minimum_required(VERSION 3.22)
project(opensr)

set(CMAKE_CXX_STANDARD 17)

if (MSVC)
    add_compile_options(/std:c++17)
    string(APPEND CMAKE_CXX_FLAGS " /EHsc")
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fexceptions")

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)
file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# Add Flecs library
add_subdirectory(libs/flecs)

# todo: refactor to modules
add_executable(opensr main.cpp Graphics/ResourceLoader.cpp Graphics/ResourceLoader.h Logic/GameObject.cpp Logic/GameObject.h Logic/Galaxy.cpp Logic/Galaxy.h Logic/Components/Position.h Logic/Components/Galaxy.h Logic/Components/Star.h Logic/Components/Ship.h)

target_link_libraries(opensr PRIVATE sfml-system sfml-window sfml-graphics sfml-network sfml-audio flecs)
