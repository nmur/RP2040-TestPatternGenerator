# PicoVGA Sample Project

## About this Project

This is a sample project for the [PicoVGA cmake](https://github.com/codaris/picovga-cmake) library to demonstrate a minimal project setup.  

## Installing the PicoVGA library

1. Make sure you have the [Pico SDK](https://github.com/raspberrypi/pico-sdk) installed.

2. Clone the PicoVGA repository  
~~~
git clone https://github.com/codaris/picovga-cmake.git
~~~

3. Set `PICOVGA_PATH` to the PicoVGA directory in your environment, or pass it (`-DPICOVGA_PATH=`) to cmake later.

## Installation

~~~
git clone https://github.com/codaris/picovga-helloworld.git
~~~

## Building

Generate the make files by running CMake:

~~~
cmake .
~~~

Build the project:

~~~
make
~~~

## The Files

* `CMakeLists.txt` - This file contains the build instructions for this project and shows how to configure the project for the Pico SDK and for PicoVGA.

* `pico_sdk_import.cmake` - This file is copied from the Pico SDK and helps CMake find the Pico SDK.

* `picovga_import.cmake` - This file is copied from the PicoVGA library and helps CMake find the PicoVGA library

* `src/vga_config.h` - This contains the PicoVGA library settings, such as the size of the render buffers. You don't usually have to change this file unless you want to change resolution or decrease the amount of RAM used.

* `src/main.cpp` - The main source file.  Initializes the display and prints "Hello World".
