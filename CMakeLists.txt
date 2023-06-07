cmake_minimum_required(VERSION 3.14)
project(opensr2)

set(CMAKE_TOOLCHAIN_FILE ${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)

# Set compiler flags based on the system
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

# Finding packages
find_package(SDL2 CONFIG REQUIRED)
find_package(Boost REQUIRED COMPONENTS filesystem)
find_package(RmlUi REQUIRED)

# Find SDL2_image library
find_library(SDL2_IMAGE_LIBRARY SDL2_image)

# Create RmlUI backend
file(GLOB RML_BACKEND_SOURCES Backends/*.cpp)
file(GLOB SYSTEM_SOURCES system/*.cpp)

add_library(rmlbackend STATIC ${RML_BACKEND_SOURCES})
target_include_directories(rmlbackend PUBLIC ${RmlUi_INCLUDE_DIRS})
target_link_libraries(rmlbackend PRIVATE SDL2::SDL2 ${SDL2_IMAGE_LIBRARY} ${RmlUi_LIBRARIES})

add_executable(opensr2 main.cpp ${SYSTEM_SOURCES})
target_include_directories(opensr2 PUBLIC Backends system ${RmlUi_INCLUDE_DIRS})
target_link_libraries(opensr2 PRIVATE SDL2::SDL2 ${SDL2_IMAGE_LIBRARY} ${RmlUi_LIBRARIES} rmlbackend)

# Include Boost directories
target_include_directories(opensr2 PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(opensr2 PRIVATE ${Boost_LIBRARIES})

# Uncomment the line below if RmlUI is a static library
# add_definitions(-DRMLUI_STATIC_LIB)
