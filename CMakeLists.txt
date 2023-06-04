cmake_minimum_required(VERSION 3.14)
project(opensr2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER "clang++")

# Add the source file(s)
add_executable(opensr2 main.cpp)

# Set the path to Boost root directory
set(BOOST_ROOT ${CMAKE_SOURCE_DIR}/extern)

# Find the Boost libraries
find_package(Boost REQUIRED COMPONENTS filesystem)

# Include Boost directories
include_directories(${Boost_INCLUDE_DIRS})

# Find the vcpkg.cmake file
find_path(VCPKG_CMAKE_PATH NAMES "vcpkg.cmake" PATHS "~/vcpkg/scripts/buildsystems/" NO_DEFAULT_PATH)

set(Rmlui_DIR "~/vcpkg/installed/x64-osx/share/rmlui/")

if(NOT VCPKG_CMAKE_PATH)
    message(FATAL_ERROR "vcpkg.cmake not found. Make sure to provide the correct path to vcpkg installation directory.")
endif()

set(CMAKE_TOOLCHAIN_FILE ${VCPKG_CMAKE_PATH} CACHE PATH "Path to vcpkg.cmake" FORCE)

# Find and include Rmlui
find_package(Rmlui REQUIRED CONFIG)
include_directories(${RmlUi_INCLUDE_DIRS})

# Link libraries
target_link_libraries(opensr2 PRIVATE ${Boost_LIBRARIES} ${RMLUI_LIBRARIES})
