cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)  # Include Pico SDK
include(picovga_import.cmake)   # Inclue PicoVGA

project(helloworld C CXX ASM)   # Helloworld project

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()                 # Initialize Pico SDK

add_compile_options(-Wall -Wno-format -Wno-unused-function -Wno-maybe-uninitialized)

# Create helloworld executable with specified source files
add_executable(helloworld
    src/main.cpp
)

# If monitor requires vsync uncomment to set the vsync pin
#add_compile_definitions(VGA_GPIO_VSYNC=9)

# Add PicoVGA to the target
add_picovga(helloworld)

# for vga_config.h include
target_include_directories(helloworld PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src
)

# Generate the uf2 output
pico_add_extra_outputs(helloworld)
