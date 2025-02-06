cmake_minimum_required(VERSION 3.0)
project(TetriCity)

# Add raylib and raylib-cpp
add_subdirectory(libs/raylib-cpp)
add_subdirectory(libs/raylib)

# Set source files
set(SOURCES 
src/Position.hpp 
src/Position.cpp 
src/Block.cpp 
src/Block.hpp 
src/Blocks.cpp 
src/Colors.cpp 
src/Colors.hpp 
src/main.cpp 
src/Game.hpp 
src/Game.cpp 
src/Grid.hpp 
src/Grid.cpp 
src/Level.hpp 
src/Level.cpp 
src/Levels.hpp 
src/Levels.cpp 
src/MainMenu.cpp
src/GameSound.hpp
src/GameSound.cpp
src/Player.cpp
src/Player.hpp
src/Menu.hpp
src/Menus.hpp
)

# Include and link directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libs/raylib-cpp/include 
                    ${CMAKE_CURRENT_SOURCE_DIR}/libs/raylib/src
                    ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Copy files from resources folder
file(COPY src/resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# Create executable
add_executable(TetriCity ${SOURCES})

# Link against raylib and raylib-cpp
target_link_libraries(TetriCity raylib raylib_cpp)

# Set standard cpp to 11
set_target_properties(TetriCity PROPERTIES CXX_STANDARD 11)