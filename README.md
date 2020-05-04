# GraftCoreX
An Arduino core for Graft Module.
GraftCoreX is based on MegaCoreX
# Table of contents


## Supported Graft Module

| Graft            | Graft Input                | Graft Output                      |Gaft Uno                     |
|------------------|----------------------------|-----------------------------------|-----------------------------|
| **Flash**        | 48 kB                      | 48 kB                             | 48 kB                       |
| **RAM**          | 6 kB                       | 6 kB                              | 6 kB                        |
| **EEPROM**       | 256 B                      | 256 B                             | 256 B                       |
| **Serial ports** | 2                          | 2                                 | 2                           |
| **IO pins**      | 8D/6D2A                    | 8D/2RL/4RL                        | 25                          |
| **SMCI bus**     | Yes                        | Yes                               | Yes                         |
| **Interrupt**    |                            |                                   |                             |
| **PWM Output**   |                            |                                   |                             |
|**Logic(CCL)**    |                            |                                   |                             |
|**Comparator(AC)**|                            |                                   |                             |


### Programming
Programming must be done with a UPDI compatible programmer, such as the microUPDI, JTAG2UPDI or an official Atmel/Microchip UPDI compatible programmer.<br/> Using Arduino bootloader

## Printf support
Unlike the official Arduino core, GraftCore has printf support out of the box. If you're not familiar with printf you should probably [read this first](https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm). It's added to the Print class and will work with all libraries that inherit Print. Printf is a standard C function that lets you format text much easier than using Arduino's built-in print and println. Note that this implementation of printf will NOT print floats or doubles. This is a limitation of the avr-libc printf implementation on AVR microcontrollers, and nothing I can easily fix.

If you're using a serial port, simply use `Serial.printf("Milliseconds since start: %ld\n", millis());`. Other libraries that inherit the Print class (and thus supports printf) are SoftwareSerial and the LiquidCrystal LCD library.



## How to install
#### Boards Manager Installation
*Not yet implemented*

#### Manual Installation
Click on the "Download ZIP" button. Extract the ZIP file, and move the extracted folder to the location "**~/Documents/Arduino/hardware**". Create the "hardware" folder if it doesn't exist.
Open Arduino IDE and a new category in the boards menu called "GraftCore" will show up.


