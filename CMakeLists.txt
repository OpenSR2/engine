cmake_minimum_required(VERSION 3.14)
project(opensr2)

set(CMAKE_TOOLCHAIN_FILE ${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake)

# Set c++ standart
set(CMAKE_CXX_STANDARD 20)
# Set compiler
if (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    set(CMAKE_C_COMPILER "clang")
    set(CMAKE_CXX_COMPILER "clang++")
elseif (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(CMAKE_C_COMPILER "clang-cl")
    set(CMAKE_CXX_COMPILER "clang-cl")
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(CMAKE_C_COMPILER "clang")
    set(CMAKE_CXX_COMPILER "clang++")
else ()
    message(FATAL_ERROR "Unsupported platform: ${CMAKE_SYSTEM_NAME}")
endif ()

# Append RMLUI_ROOT to CMAKE_PREFIX_PATH
list(APPEND CMAKE_PREFIX_PATH $ENV{RMLUI_ROOT})

# Finding packeges
find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_Image CONFIG REQUIRED)
find_package(Boost REQUIRED COMPONENTS filesystem)
find_package(RmlUi REQUIRED)

# Create RmlUI backend
add_library(rmlbackend STATIC Backends/RmlUi_Backend_SDL_SDLrenderer.cpp)
file(GLOB RML_BACKEND_SOURCES Backends/*.cpp)
file(GLOB SYSTEM_SOURCES system/*.cpp)
target_sources(rmlbackend PUBLIC
        ${RML_BACKEND_SOURCES}
        )

add_executable(opensr2 main.cpp)

# Include Boost directories for all
include_directories(${Boost_INCLUDE_DIRS})
link_libraries(${Boost_LIBRARIES})


target_include_directories(rmlbackend PUBLIC ${RmlUi_INCLUDE_DIRS})
target_link_libraries(rmlbackend SDL2::SDL2 SDL2_image)
target_link_libraries(rmlbackend ${RmlUi_LIBRARIES})

target_include_directories(opensr2 PUBLIC Backends)
target_include_directories(opensr2 PUBLIC system)
target_include_directories(opensr2 PUBLIC ${RmlUi_INCLUDE_DIRS})
target_sources(opensr2 PUBLIC
        ${SYSTEM_SOURCES}
        )
target_link_libraries(opensr2 SDL2::SDL2 SDL2_image)
target_link_libraries(opensr2 ${RmlUi_LIBRARIES})
target_link_libraries(opensr2 rmlbackend)

# add_definitions(-DRMLUI_STATIC_LIB)