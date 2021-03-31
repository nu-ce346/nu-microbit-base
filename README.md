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

        cd /tmp \
        && wget -c https://developer.arm.com/-/media/Files/downloads/gnu-rm/9-2020q2/gcc-arm-none-eabi-9-2020-q2-update-x86_64-linux.tar.bz2 \
        && tar xjf gcc-arm-none-eabi-9-2020-q2-update-x86_64-linux.tar.bz2 \
        && sudo mv gcc-arm-none-eabi-9-2020-q2-update /opt/gcc-arm-none-eabi-9-2020-q2-update \
        && rm gcc-arm-none-eabi-9-2020-q2-update-x86_64-linux.tar.bz2 \
        && sudo ln -s /opt/gcc-arm-none-eabi-9-2020-q2-update/bin/* /usr/local/bin/.

    On MacOS:

        brew tap ArmMbed/homebrew-formulae
        brew install arm-none-eabi-gcc

 3. JTAG programming tools: [Segger JLink](https://www.segger.com/jlink-software.html)

    Pick the correct package for your OS under "Software and documentation pack".

 4. Update the JTAG firmware on your Micro:bit v2

    Follow the instructions here: https://www.segger.com/products/debug-probes/j-link/models/other-j-links/bbc-microbit-j-link-upgrade/

    (You can later restore the original firmware with the instructions here: https://microbit.org/get-started/user-guide/firmware/)


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
$ miniterm /dev/ttyACM0 38400
```

