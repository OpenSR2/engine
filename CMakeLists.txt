cmake_minimum_required(VERSION 3.14)
project(opensr2)

set(CMAKE_CXX_STANDARD 14)

# Add the source file(s)
add_executable(opensr2 main.cpp)

# Set the path to Boost root directory
set(BOOST_ROOT ${CMAKE_SOURCE_DIR}/extern)

# Find the Boost libraries
find_package(Boost REQUIRED COMPONENTS system)

# Include Boost directories
include_directories(${Boost_INCLUDE_DIRS})

# Link Boost libraries
target_link_libraries(opensr2 PRIVATE ${Boost_LIBRARIES})
