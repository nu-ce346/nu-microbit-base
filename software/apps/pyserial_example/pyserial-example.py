#! /usr/bin/env python3

import time
import argparse
import serial
from serial.tools import list_ports

# automatically determine if a device is a microbit
def find_microbit_port():
    for p in list_ports.comports():
        if p.vid == 0x0D28 and p.pid == 0x0204:
            return p.device
    return None

def main():
    # parse arguments
    parser = argparse.ArgumentParser()
    parser.add_argument("--port", default=None)
    parser.add_argument("--baud", default=38400, type=int)
    args = parser.parse_args()

    # determine the port
    port = args.port or find_microbit_port()
    if port is None:
        print("No micro:bit found")
        return

    # open microbit serial port
    print(f"Opening {port} @ {args.baud}...")
    ser = serial.Serial(
        port,
        args.baud,
        timeout=0.5,
        write_timeout=0,
        inter_byte_timeout=0
    )

    time.sleep(3.5)
    ser.reset_input_buffer()

    print("Connected...\n")

    counter = 0
    while True:
        # Write Test
        payload = f"{counter} {counter+0.5}"
        print(f"TX -> {payload}")
        ser.write(payload.encode("ascii"))

        time.sleep(0.02)
        ser.write(b"\n")
        ser.flush()

        # Read Test
        time.sleep(0.1)

        while ser.in_waiting > 0:
            line = ser.readline().decode("ascii", errors="ignore").strip()
            print(f"RX <- {line}")
        else:
            print("RX <- (end of data)")

        counter += 1
        time.sleep(1)

if __name__ == "__main__":
    main()
