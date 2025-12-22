Pyserial Example App
====================

Reads data from serial. This demonstrates how to communicate from a computer to
a Microbit. Thanks to student Du Chen who contributed this in Fall 2025.

After loading this application onto a Microbit (with `make flash`), you should
run the pyserial-example.py script to demonstrate bi-directional communication.

```
$ ./pyserial-example.py 
Opening /dev/ttyACM0 @ 38400...
Connected...

TX -> 0 0.5
RX <- GOT: Integer = 0, Float = 0.500000
RX <- (end of data)
TX -> 1 1.5
RX <- GOT: Integer = 1, Float = 1.500000
RX <- (end of data)
TX -> 2 2.5
RX <- GOT: Integer = 2, Float = 2.500000
RX <- (end of data)
TX -> 3 3.5
```

The input data can be also be generated manually. In your serial console, just
type values and hit enter. Note that echo is not performed by this application,
so you will not see keystrokes as you type. For example, if you type "17 2.3"
and hit enter, you will receive the following output:

```
GOT: Integer = 17, Float = 2.300000
```

