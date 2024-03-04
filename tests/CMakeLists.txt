# Assuming TEST_SOURCES is correctly globbing all your test and mock files
file(GLOB TEST_SOURCES "*.c")
file(GLOB MAIN_SOURCES "${CMAKE_SOURCE_DIR}/src/*.c")
list(REMOVE_ITEM MAIN_SOURCES "${CMAKE_SOURCE_DIR}/src/main.c") # Exclude main.c for test build
set(ALL_SOURCES ${TEST_SOURCES} ${MAIN_SOURCES})

# Include the current source directory for test headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Include the main source directory for access to application headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)

# Include the Unity and Unity Fixture directories (adjust paths as necessary)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../unity/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../extras/fixture/src)

# Add executable for your tests
add_executable(run_tests ${ALL_SOURCES})

# Link the Unity framework and any other necessary libraries
target_link_libraries(run_tests PRIVATE unity::framework)
