cmake_minimum_required(VERSION 3.16)

project(vx)

message(STATUS "Building ${PROJECT_NAME}")

# You may need to specify the path to your source files.
message(STATUS "File: ${C_FILE}")

# Set the C++ version to C++23 (recommended approach)
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
#set(CMAKE_C_EXTENSIONS OFF)  # Optional: Disable compiler-specific extensions like `gnu++`

# Define your target
add_executable(${PROJECT_NAME} src/main.c src/init.c src/process_n_execute.c src/input.c src/raw_mode.c)

# Apply the compile options (target-specific)
target_compile_options(${PROJECT_NAME} PRIVATE 
    -fsanitize=address  # Enable AddressSanitizer
    -fdiagnostics-color=always  # Enable colored diagnostics (useful for readability)
    -O3
    -std=c23
)

# Optionally link the AddressSanitizer runtime (needed for AddressSanitizer to work)
target_link_libraries(${PROJECT_NAME} PRIVATE -fsanitize=address)
