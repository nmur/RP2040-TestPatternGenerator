# RP2040-TestPatternGenerator

This is a simple test pattern generator that runs on the RP2040 microcontroller. It uses the [PicoVGA cmake](https://github.com/codaris/picovga-cmake) library for outputting a 15kHz 240p RGBS signal via a VGA connector.

## How to Use

1. Download the [latest release](https://github.com/nmur/RP2040-TestPatternGenerator/releases).
2. Hold the BOOT button on the RP2040 device and connect it to your PC. A file browser window for the device should appear.
3. Drag and drop the `RP2040-TestPatternGenerator.uf2` file onto the device. It should automatically close when completed.

## Building

1. Clone the PicoSDK and PicoVGA repositories:
~~~
git clone https://github.com/codaris/picovga-cmake.git
git clone https://github.com/raspberrypi/pico-sdk
~~~

2. Set `PICOVGA_PATH` to the PicoVGA directory and the `PICO_SDK_PATH` to the PicoSDK directory in your environment.

3. Generate the make files by running CMake:
~~~
cmake .
~~~

4. Build the project:
~~~
make
~~~

## Acknowledgements

- Miroslav Nemecek (Panda38@seznam.cz) for their [PicoVGA library](https://github.com/Panda381/PicoVGA)
- Wayne Venables (codaris) for their [PicoVGA fork](https://github.com/codaris/picovga-cmake)