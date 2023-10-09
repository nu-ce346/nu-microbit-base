# Northwestern Micro:bit v2 Base

Starter code for Northwestern course CE346 based on Micro:bit v2.

This repository has applications and board initialization that connects to the
build system provided by [nrf52x-base](https://github.com/lab11/nrf52x-base).


## Requirements
 
 1. Various tools
 
    * build-essential (make)
    * git
    * python3
    * pyserial (`sudo apt install python3-serial`)

 2. ARM cross-compiler toolchain: [gcc-arm-none-eabi toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads)

    On Ubuntu:

        sudo apt install gcc-arm-none-eabi

    On MacOS:

        brew tap ArmMbed/homebrew-formulae
        brew update
        brew install ARMmbed/homebrew-formulate/arm-none-eabi-gcc

 3. JTAG programming tools: OpenOCD

    On Ubuntu:

        sudo apt install openocd

    On MacOS:

        brew install open-ocd


## Installation

 * Clone the repository
 * Change directory into the repository
 * `git submodule update --init --recursive` (this will take a couple minutes to complete)


## Building and loading applications

To build an application, use `make` inside of the application's directory.

`make flash` uploads the application to the board using JTAG.


## Getting print data

The Micro:bit v2 prints information through a serial port at 38400 baud. You
can connect with any serial terminal, but miniterm comes with pyserial and
works pretty well for this.

```
$ pyserial-miniterm /dev/ttyACM0 38400
```

