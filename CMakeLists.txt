cmake_minimum_required(VERSION 3.10)
project(main C)

# Set the C standard
set(CMAKE_C_STANDARD 11)

# Specify the include directories for SDL2 and SDL2_image
include_directories(/opt/homebrew/include)  # General includes
include_directories(/opt/homebrew/include/SDL2)  # SDL2 specific include

# Specify the library directories
link_directories(/opt/homebrew/lib)  # General libraries
link_directories(/opt/homebrew/Cellar/sdl2_image/2.8.6/lib)  # SDL2_image library
link_directories(/opt/homebrew/Cellar/sdl2_mixer/2.8.1_1/lib)

# Find the SDL2 and SDL2_image packages
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)

# Add executable target
add_executable(main code/main.c)

# Link SDL2 and SDL2_image libraries to your executable
target_link_libraries(main SDL2::SDL2 SDL2_image::SDL2_image SDL2_mixer::SDL2_mixer)
