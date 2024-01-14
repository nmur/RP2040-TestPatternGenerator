cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)  # Include Pico SDK
include(picovga_import.cmake)   # Inclue PicoVGA

project(RP2040-TestPatternGenerator C CXX ASM)   # project

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()                 # Initialize Pico SDK

add_compile_options(-Wall -Wno-format -Wno-unused-function -Wno-maybe-uninitialized)

# Create executable with specified source files
add_executable(RP2040-TestPatternGenerator
    src/main.cpp
)

# If monitor requires vsync uncomment to set the vsync pin
#add_compile_definitions(VGA_GPIO_VSYNC=9)

# Add PicoVGA to the target
add_picovga(RP2040-TestPatternGenerator)

# for vga_config.h include
target_include_directories(RP2040-TestPatternGenerator PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src
)

# Generate the uf2 output
pico_add_extra_outputs(RP2040-TestPatternGenerator)
