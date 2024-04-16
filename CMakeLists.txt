cmake_minimum_required(VERSION 3.8)
project(summarization VERSION 0.1.0 LANGUAGES C CXX)

# Set C++ standard to 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the path to the SQLite amalgamation directory
set(SQLITE "${CMAKE_SOURCE_DIR}/libs/sqlite-amalgamation-3450300")

# Include the SQLite amalgamation directly into the project
add_library(sqlite3 STATIC ${SQLITE}/sqlite3.c)

# Add include directories for SQLite
target_include_directories(sqlite3 PUBLIC ${SQLITE})

# Define the executable and its source files
add_executable(summarization main.cpp)

# Link the SQLite library with our project
target_link_libraries(summarization PRIVATE sqlite3)
