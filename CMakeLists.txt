cmake_minimum_required(VERSION 3.22)
project(opensr)

set(CMAKE_CXX_STANDARD 17)

# Set compiler-specific flags
if (MSVC)
    add_compile_options(/std:c++17)
    string(APPEND CMAKE_CXX_FLAGS " /EHsc")
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fexceptions")

# Find and include SFML
find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)

# Copy assets directory to build directory
file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# Create a list of your source files
set(SOURCES
        main.cpp
        Graphics/ResourceLoader.cpp
        Logic/GameObject.cpp
        Logic/Galaxy.cpp
        Logic/Entity.cpp
        Logic/RenderSystem.cpp
        Logic/PlanetSystem.cpp
        Logic/ShipSystem.cpp
        )

# Add an executable target
add_executable(opensr ${SOURCES})

# Link against SFML libraries
target_link_libraries(opensr sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
