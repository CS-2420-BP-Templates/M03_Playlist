cmake_minimum_required(VERSION 3.27)
project(03_Playlist)

set(CMAKE_CXX_STANDARD 17)

# IMPORTANT: Enable CTest support
enable_testing()

# Create the library
set(LIB_NAME mylib)

add_library(${LIB_NAME}
        PlaylistVector.cpp   # Only the .cpp file
)
target_include_directories(${LIB_NAME} PUBLIC 03_Playlist)

# Main program
add_executable(03_Playlist
        main.cpp
)

target_link_libraries(03_Playlist
        PUBLIC ${LIB_NAME}
)
add_subdirectory(tests)

