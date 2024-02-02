# RP2040-TestPatternGenerator

This is a simple test pattern generator that runs on the RP2040 microcontroller. It uses the [PicoVGA cmake](https://github.com/codaris/picovga-cmake) library for outputting a 15kHz 240p RGBS signal via a VGA connector. This tool is aimed to be used for rudimentary tests for checking basic CRT TV functionality, not for accurate calibration.

## Limitations

This program can only output colours in the RGB332 space, so each of the three colour channels (Red, Green, and Blue) are represented by 3, 3, and 2 bits, respectively. More information can be found [here](https://github.com/nmur/RP2040-TestPatternGenerator/wiki/Limitations).

## Initial Setup

1. Download the [latest release](https://github.com/nmur/RP2040-TestPatternGenerator/releases).
2. Hold the BOOT button on the RP2040 device and connect it to your PC. A file browser window for the device should appear.
3. Drag and drop the `RP2040-TestPatternGenerator.uf2` file onto the device. It should automatically close when completed.

## How to Use

- Press the connected button to cycle through patterns.
- To flash a newer firmware once the device is installed in an enclosure and the BOOT button is inaccessable, connect the device to your computer, hold the same button for 3 seconds and release. The device will reboot into flash mode.

## Building

1. Generate the make files by running CMake:
~~~
cmake .
~~~

2. Build the project:
~~~
make
~~~

## Acknowledgements

- Miroslav Nemecek (Panda38@seznam.cz) for their [PicoVGA library](https://github.com/Panda381/PicoVGA)
- Wayne Venables (codaris) for their [PicoVGA fork](https://github.com/codaris/picovga-cmake)
- Turi Scandurra (TuriSc) for their [RP2040-Button library](https://github.com/TuriSc/RP2040-Button)
