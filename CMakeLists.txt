cmake_minimum_required(VERSION 3.10) # Specify the minimum version for CMake

project(UnitTestFramework LANGUAGES C) # Replace with your project name and version

# Set the C standard you wish to use (e.g., C99)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Automatically add all source files from the src directory
file(GLOB SOURCES "src/*.c")

# Include the src directory for header files
include_directories(src)

add_subdirectory(unity)

# Add executable based on the automatically collected source files
add_executable(${PROJECT_NAME} ${SOURCES})

# If you have any libraries to link, use this
target_link_libraries(${PROJECT_NAME} PRIVATE unity::framework)
