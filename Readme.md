# RP2040-TestPatternGenerator

This is a simple test pattern generator that runs on the RP2040 microcontroller. It uses the [PicoVGA cmake](https://github.com/codaris/picovga-cmake) library for outputting a 15kHz 240p RGBS signal via a VGA connector. This tool is aimed to be used for rudimentary tests for checking basic CRT TV functionality, not for accurate calibration.  

Its main features are:  
- **Cheap**: Approximately <$15 USD in parts, less if you already have some components or if you want to make a few.
- **Accessible**: Open source. Soldering is easy enough even for a first timer.
- **Small**: Roughly 2x2"/50x50mm in size.
- **Fast**: Boots and changes patterns instantly.
- **Portable**: Very low power draw, works with a powerbank.

[<img src="https://github.com/nmur/RP2040-TestPatternGenerator/assets/8315014/7c5d83b8-fa1e-4127-8eaf-c0302f727538" width="50%"/>](https://github.com/nmur/RP2040-TestPatternGenerator/assets/8315014/7c5d83b8-fa1e-4127-8eaf-c0302f727538)[<img src="https://github.com/nmur/RP2040-TestPatternGenerator/assets/8315014/ee1879ff-74e5-49d6-872a-809746e85480" width="50%"/>](https://github.com/nmur/RP2040-TestPatternGenerator/assets/8315014/ee1879ff-74e5-49d6-872a-809746e85480)

## Limitations

This program can only output colours in the RGB332 space, so each of the three colour channels (Red, Green, and Blue) are represented by 3, 3, and 2 bits, respectively. More information can be found [here](https://github.com/nmur/RP2040-TestPatternGenerator/wiki/Limitations).

## Getting Started

1. [Obtain all the components and assemble the device](https://github.com/nmur/RP2040-TestPatternGenerator/wiki/Assembly).
2. Download the [latest firmware](https://github.com/nmur/RP2040-TestPatternGenerator/releases).
3. Hold the BOOT button on the RP2040 device and connect it to your PC. A file browser window for the device should appear.
4. Drag and drop the `RP2040-TestPatternGenerator.uf2` file onto the device. It should automatically close when completed.

## How to Use

- [Connect the device to your TV](https://github.com/nmur/RP2040-TestPatternGenerator/wiki/Frequently-Asked-Questions#how-do-i-connect-this-to-my-crt-tv), and connect a USB-C cable for power.
- Press the connected button to cycle through patterns.
- To flash a newer firmware, follow the same firmware installation steps from the [Getting Started](https://github.com/nmur/RP2040-TestPatternGenerator/tree/main?tab=readme-ov-file#getting-started) section. Once the device is installed in an enclosure and the BOOT button is inaccessable, connect the device to your computer, hold the same button for 3 seconds and release. The device will reboot into flash mode.

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
