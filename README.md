# E2LP NES
**E2LP NES** is port of [fpga_nes](https://github.com/brianbennett/fpga_nes), fpga-targeted Nintento Entertainment System emulator written in Verilog, for [E2LP](http://www.e2lp.org/).

It is currently under development, and is most notably missing support for mappers and the DMC sound channel.  At this point, it runs most [NROM](http://www.thenesdump.com/Mappers/NROM.htm) games capably (e.g., Super Mario Brothers, Excitebike).

In addition, this project includes a C++ Windows application called NesDbg, which communicates with the FPGA over USB UART to load ROMs, run unit tests, readwrite memory, etc. Project also contains an Arduino sketch for testing NES compatible gamepads.

## Hardware Setup:
1. [E2LP](http://moodle.e2lp.org/course/view.php?id=5&section=100) develpoment board.
2. VGA display connection for NES video output.
3. RS-232 cable for communication between NES and NesDbg software.
4. Piezo buzzer.
5. 2 [famiclone](https://en.wikipedia.org/wiki/Nintendo_Entertainment_System_hardware_clone) joypads.

## Connections
| WIRE          | PORT          |
| ------------- |:-------------:|
| Joypad latch  | *GPIO 3*      |
| Joypad clock  | *GPIO 5*      |
| Joypad 1 data | *GPIO 1*      |
| Joypad 2 data | *GPIO 7*      |
| Piezo buzzer  | *GPIO 2*      |
| Sound volume  | *SW 0 - SW 3* |
| CPU Reset     | *SW 4*        |
| TX indicator  | *LED 0*       |
| RX indicator  | *LED 7*       |

More information about [famiclone](https://en.wikipedia.org/wiki/Nintendo_Entertainment_System_hardware_clone) joypad connectors [here](famiclone_controller_pinout.md)

## Development Environment:
1. [ISE WebPack](http://www.xilinx.com/support/download/index.htm)
2. [Visual Studio 2010 Express](http://www.microsoft.com/visualstudio/en-us/products/2010-editions/visual-cpp-express)
3. [Arduino IDE](https://www.arduino.cc/en/Main/Software)
