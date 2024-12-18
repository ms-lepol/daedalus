cmake_minimum_required(VERSION 3.10)

# Set the project name
project(OctoDungeonTUI)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)

FetchContent_Declare(ftxui
GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
GIT_TAG v5.0.0
)
message(STATUS "Fetching ftxui")

FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
    FetchContent_Populate(ftxui)
    add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()


# Create a shared library .so file from the source files
add_library(daedalus SHARED src/daedalus/dungeon.cpp)

# Add the executable
add_executable(ftxui-starter src/main.cpp)
target_link_libraries(ftxui-starter
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component # Not needed for this example.
)

# Include directories
include_directories(include)

# Link libraries (if any)
# target_link_libraries(OctoDungeonTUI <library_name>)