/****************************************************|
|               48-PIN STANDARD PINOUT               |
|       https://github.com/MCUdude/MegaCoreX         |
|                                                    |
| COMPATIBLE WITH:                                   |
| ATmega4809                                         |
| ATmega3209                                         |
| ATmega1609                                         |
| ATmega809                                          |
|                                                    |
| Note that this pinout is not directly compatible   |
| with the UNO Wifi Rev2 hardware without performing |
| pinswaps. This pinout is supposed to be as close   |
| to the metal as possible. The only peripherals     |
| that are swapped to other pins by default are the  |
| PWM outputs.                                       |
|                                                    |
|****************************************************/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>
#include "timers.h"

#define GRAFT_UNO_PINOUT

#define NUM_DIGITAL_PINS               30
#define NUM_ANALOG_INPUTS              11
#define NUM_RESERVED_PINS              0
#define NUM_INTERNALLY_USED_PINS       0
#define NUM_I2C_PINS                   2 // (SDA / SCL)
#define NUM_SPI_PINS                   3 // (MISO / MOSI / SCK)
#define NUM_TOTAL_FREE_PINS            (NUM_DIGITAL_PINS)
#define NUM_TOTAL_PINS                 (NUM_DIGITAL_PINS)
#define ANALOG_INPUT_OFFSET            20
#define LED_BUILTIN                    27 // PA4
#define digitalPinToAnalogInput(p)     ((p < NUM_ANALOG_INPUTS) ? (p) : ((p) >= 22 && (p) <= 33) ? ((p) - ANALOG_INPUT_OFFSET) : ((p) >= 36 && (p) <=39) ? ((p) - 2 - ANALOG_INPUT_OFFSET) : NOT_A_PIN)
#define digitalOrAnalogPinToDigital(p) ((p <= 11) ? ((p) + ANALOG_INPUT_OFFSET) : ((p) <= 15) ? ((p) + ANALOG_INPUT_OFFSET + 2) : (((p) >= 22 && (p) <= 33) || ((p) >= 36 && (p) <= 39)) ? (p) :  NOT_A_PIN)

#if !defined(MILLIS_USE_TIMERB0) || !defined(MILLIS_USE_TIMERB1) || !defined(MILLIS_USE_TIMERB2) || !defined(MILLIS_USE_TIMERB3)
#define MILLIS_USE_TIMERB2 // Use TCB2 for millis generation
#endif

#define EXTERNAL_NUM_INTERRUPTS     (30)

#if defined(MILLIS_USE_TIMERB0)
    #define digitalPinHasPWM(p)     (((p) >= 12 && (p) <= 19) || (p) == 39)
#elif defined(MILLIS_USE_TIMERB1)
    #define digitalPinHasPWM(p)     (((p) >= 12 && (p) <= 19) || (p) == 38)
#elif defined(MILLIS_USE_TIMERB2)
    #define digitalPinHasPWM(p)     (((p) >= 13 && (p) <= 19) || (p) == 38 || (p) == 39)
#else // default to MILLIS_USE_TIMERB3
    #define digitalPinHasPWM(p)     ((p) == 12 || ((p) >= 14 && (p) <= 19) || (p) == 38 || (p) == 39)
#endif

// Timer pin swaps
#define TCA0_PINS PORTMUX_TCA0_PORTC_gc
#define TCB0_PINS PORTMUX_TCB0_bm
#define TCB1_PINS PORTMUX_TCB1_bm
#define TCB2_PINS PORTMUX_TCB2_bm
#define TCB3_PINS 0x00

// SPI 0
// No pinswap enabled by default
// Pinswap 2 not available
#define SPI_INTERFACES_COUNT   1
#define SPI_MUX                (PORTMUX_SPI0_DEFAULT_gc)
//#define SPI_MUX_PINSWAP_1      (PORTMUX_SPI0_ALT1_gc)
//#define SPI_MUX_PINSWAP_2      (PORTMUX_SPI0_ALT2_gc)
#define PIN_SPI_MISO           (12)
#define PIN_SPI_SCK            (13)
#define PIN_SPI_MOSI           (11)
#define PIN_SPI_SS             (8)

static const uint8_t SS   = PIN_SPI_SS;
static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SCK  = PIN_SPI_SCK;

// TWI 0
// No pinswap enabled by default
#define TWI_MUX                (PORTMUX_TWI0_DEFAULT_gc)
#define TWI_MUX_PINSWAP        (PORTMUX_TWI0_ALT2_gc)
#define PIN_WIRE_SDA           (9)
#define PIN_WIRE_SCL           (10)
#define PIN_WIRE_SDA_PINSWAP_1 (21)
#define PIN_WIRE_SCL_PINSWAP_1 (22)
static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

// USART 0
// No pinswap by default
#define HWSERIAL0 (&USART0)
#define HWSERIAL0_DRE_VECTOR            (USART0_DRE_vect)
#define HWSERIAL0_DRE_VECTOR_NUM        (USART0_DRE_vect_num)
#define HWSERIAL0_RXC_VECTOR            (USART0_RXC_vect)
#define HWSERIAL0_MUX                   (PORTMUX_USART0_DEFAULT_gc)
#define HWSERIAL0_MUX_PINSWAP_1         (PORTMUX_USART0_ALT1_gc)
#define PIN_WIRE_HWSERIAL0_TX           (0)
#define PIN_WIRE_HWSERIAL0_RX           (1)
#define PIN_WIRE_HWSERIAL0_TX_PINSWAP_1 (4)
#define PIN_WIRE_HWSERIAL0_RX_PINSWAP_1 (5)

// USART1
// No pinswap by default
#define HWSERIAL1                       (&USART1)
#define HWSERIAL1_DRE_VECTOR            (USART1_DRE_vect)
#define HWSERIAL1_DRE_VECTOR_NUM        (USART1_DRE_vect_num)
#define HWSERIAL1_RXC_VECTOR            (USART1_RXC_vect)
#define HWSERIAL1_MUX                   (PORTMUX_USART1_DEFAULT_gc)
#define HWSERIAL1_MUX_PINSWAP_1         (PORTMUX_USART1_ALT1_gc)
#define PIN_WIRE_HWSERIAL1_TX           (14)
#define PIN_WIRE_HWSERIAL1_RX           (15)
#define PIN_WIRE_HWSERIAL1_TX_PINSWAP_1 (18)
#define PIN_WIRE_HWSERIAL1_RX_PINSWAP_1 (19)

// USART 2
// No pinswap by default
#define HWSERIAL2 (&USART2)
#define HWSERIAL2_DRE_VECTOR            (USART2_DRE_vect)
#define HWSERIAL2_DRE_VECTOR_NUM        (USART2_DRE_vect_num)
#define HWSERIAL2_RXC_VECTOR            (USART2_RXC_vect)
#define HWSERIAL2_MUX                   (PORTMUX_USART2_DEFAULT_gc)
#define HWSERIAL2_MUX_PINSWAP_1         (PORTMUX_USART2_ALT1_gc)
#define PIN_WIRE_HWSERIAL2_TX           (34)
#define PIN_WIRE_HWSERIAL2_RX           (35)
#define PIN_WIRE_HWSERIAL2_TX_PINSWAP_1 (28)
#define PIN_WIRE_HWSERIAL2_RX_PINSWAP_1 (29)

// USART 3
// No pinswap by default
#define HWSERIAL3                       (&USART3)
#define HWSERIAL3_DRE_VECTOR            (USART3_DRE_vect)
#define HWSERIAL3_DRE_VECTOR_NUM        (USART3_DRE_vect_num)
#define HWSERIAL3_RXC_VECTOR            (USART3_RXC_vect)
#define HWSERIAL3_MUX                   (PORTMUX_USART3_DEFAULT_gc)
#define HWSERIAL3_MUX_PINSWAP_1         (PORTMUX_USART3_ALT1_gc)
#define PIN_WIRE_HWSERIAL3_TX           (8)
#define PIN_WIRE_HWSERIAL3_RX           (9)
#define PIN_WIRE_HWSERIAL3_TX_PINSWAP_1 (12)
#define PIN_WIRE_HWSERIAL3_RX_PINSWAP_1 (13)


// USART DEBUG
// No pinswap by default
#define HWSERIAL_DEBUG (&USART2)
#define HWSERIAL_DEBUG_DRE_VECTOR            (USART2_DRE_vect)
#define HWSERIAL_DEBUG_DRE_VECTOR_NUM        (USART2_DRE_vect_num)
#define HWSERIAL_DEBUG_RXC_VECTOR            (USART2_RXC_vect)
#define HWSERIAL_DEBUG_MUX                   (PORTMUX_USART2_DEFAULT_gc)
#define HWSERIAL_DEBUG_MUX_PINSWAP_1         (PORTMUX_USART2_ALT1_gc)
#define PIN_WIRE_HWSERIAL_DEBUG_TX           (34)
#define PIN_WIRE_HWSERIAL_DEBUG_RX           (35)
#define PIN_WIRE_HWSERIAL_DEBUG_TX_PINSWAP_1 (28)
#define PIN_WIRE_HWSERIAL_DEBUG_RX_PINSWAP_1 (29)

#define PIN_A0   (14)
#define PIN_A1   (15)
#define PIN_A2   (16)
#define PIN_A3   (17)
#define PIN_A4   (18)
#define PIN_A5   (19)
#define PIN_A6   (20)
#define PIN_A7   (11)
#define PIN_A8   (12)
#define PIN_A9   (13)
#define PIN_A10  (8)


static const uint8_t A0  = PIN_A0;
static const uint8_t A1  = PIN_A1;
static const uint8_t A2  = PIN_A2;
static const uint8_t A3  = PIN_A3;
static const uint8_t A4  = PIN_A4;
static const uint8_t A5  = PIN_A5;
static const uint8_t A6  = PIN_A6;
static const uint8_t A7  = PIN_A7;
static const uint8_t A8  = PIN_A8;
static const uint8_t A9  = PIN_A9;
static const uint8_t A10 = PIN_A10;
static const uint8_t AREF = 20;

#define PIN_PC5 0
#define PIN_PC4 1
#define PIN_PA0 2
#define PIN_PB0 3
#define PIN_PC6 4
#define PIN_PB1 5
#define PIN_PB2 6
#define PIN_PA1 7
#define PIN_PE3 8
#define PIN_PA2 9
#define PIN_PA3 10
#define PIN_PE0 11
#define PIN_PE1 12
#define PIN_PE2 13
#define PIN_PD0 14
#define PIN_PD1 15
#define PIN_PD2 16
#define PIN_PD3 17
#define PIN_PD4 18
#define PIN_PD5 19
#define PIN_PD7 20
#define PIN_PC2 21
#define PIN_PC3 22
#define PIN_PA7 23
#define PIN_PF0 24
#define PIN_PF1 25
#define PIN_PF2 26


#define PINS_COUNT    (30u)


#ifdef ARDUINO_MAIN

const uint8_t digital_pin_to_port[] = {
  PC, // 0 PC5/TCA0 PWM
  PC, // 1 PC4/TCA0 PWM  
  PA, // 2 PA0/USART0_Tx/CLKIN
  PB, // 3 PB0/USART3_Tx
  PC, // 4 PC6
  PB, // 5 PB1/USART3_Rx
  PB, // 6 PB2  
  PA, // 7 PA1/USART0_Rx
  PE, // 8 PE3/AIN11
  PA, // 9 PA2/SDA
  PA, // 10 PA3/SCL
  PE, // 11 PE0/AIN8
  PE, // 12 PE1/AIN9
  PE, // 13 PE2/AIN10
  PD, // 14 PD0/AIN0
  PD, // 15 PD1/AIN1
  PD, // 16 PD2/AIN2
  PD, // 17 PD3/AIN3
  PD, // 18 PD4/AIN4
  PD, // 19 PD5/AIN5
  PD, // 20 PD7/AIN7/AREF
  PC, // 21 PC2/TCA0 PWM/SDA
  PC, // 22 PC3/TCA0 PWM/SCL
  PA, // 23 PA7/SS/CLKOUT
  PF, // 24 PF0/USART2_Tx/TOSC1
  PF, // 25 PF1/USART2_Rx/TOSC2
  PF, // 26 PF2/AIN12  
  
  PA, // 27 PA4/MOSI/LED_BUILTIN
  PF, // 28 PF4/AIN14/TCB0 PWM
  PF // 29 PF5/AIN15/TCB1 PWM
};

/* Use this for accessing PINnCTRL register */
const uint8_t digital_pin_to_bit_position[] = {
  PIN5_bp, // 0 PC5/TCA0 PWM
  PIN4_bp, // 1 PC4/TCA0 PWM
  PIN0_bp, // 2 PA0/USART0_Tx/CLKIN
  PIN0_bp, // 3 PB0/USART3_Tx
  PIN6_bp, // 4 PC6
  PIN1_bp, // 5 PB1/USART3_Rx
  PIN2_bp, // 6 PB2
  PIN1_bp, // 7 PA1/USART0_Rx
  PIN3_bp, // 8 PE3/AIN11	
  PIN2_bp, // 9 PA2/SDA
  PIN3_bp, // 10 PA3/SCL
  PIN0_bp, // 11 PE0/AIN8
  PIN1_bp, // 12 PE1/AIN9
  PIN2_bp, // 13 PE2/AIN10
  PIN0_bp, // 14 PD0/AIN0
  PIN1_bp, // 15 PD1/AIN1
  PIN2_bp, // 16 PD2/AIN2
  PIN3_bp, // 17 PD3/AIN3
  PIN4_bp, // 18 PD4/AIN4
  PIN5_bp, // 19 PD5/AIN5
  PIN7_bp, // 20 PD7/AIN7/AREF
  PIN2_bp, // 21 PC2/TCA0 PWM/SDA
  PIN3_bp, // 22 PC3/TCA0 PWM/SCL
  PIN7_bp, // 23 PA7/SS/CLKOUT
  PIN0_bp, // 24 PF0/USART2_Tx/TOSC1
  PIN1_bp, // 25 PF1/USART2_Rx/TOSC2
  PIN2_bp, // 26 PF2/AIN12  
  
  PIN4_bp, // 27 PA4/MOSI/LED_BUILTIN
  PIN4_bp, // 28 PF4/AIN14/TCB0 PWM
  PIN5_bp // 29 PF5/AIN15/TCB1 PWM
};

/* Use this for accessing PINnCTRL register */
const uint8_t digital_pin_to_bit_mask[] = {
  PIN5_bm, // 0 PC5/TCA0 PWM
  PIN4_bm, // 1 PC4/TCA0 PWM
  PIN0_bm, // 2 PA0/USART0_Tx/CLKIN
  PIN0_bm, // 3 PB0/USART3_Tx
  PIN6_bm, // 4 PC6
  PIN1_bm, // 5 PB1/USART3_Rx
  PIN2_bm, // 6 PB2
  PIN1_bm, // 7 PA1/USART0_Rx
  PIN3_bm, // 8 PE3/AIN11	
  PIN2_bm, // 9 PA2/SDA
  PIN3_bm, // 10 PA3/SCL
  PIN0_bm, // 11 PE0/AIN8
  PIN1_bm, // 12 PE1/AIN9
  PIN2_bm, // 13 PE2/AIN10
  PIN0_bm, // 14 PD0/AIN0
  PIN1_bm, // 15 PD1/AIN1
  PIN2_bm, // 16 PD2/AIN2
  PIN3_bm, // 17 PD3/AIN3
  PIN4_bm, // 18 PD4/AIN4
  PIN5_bm, // 19 PD5/AIN5
  PIN7_bm, // 20 PD7/AIN7/AREF
  PIN2_bm, // 21 PC2/TCA0 PWM/SDA
  PIN3_bm, // 22 PC3/TCA0 PWM/SCL
  PIN7_bm, // 23 PA7/SS/CLKOUT
  PIN0_bm, // 24 PF0/USART2_Tx/TOSC1
  PIN1_bm, // 25 PF1/USART2_Rx/TOSC2
  PIN2_bm, // 26 PF2/AIN12  
  
  PIN4_bm, // 27 PA4/MOSI/LED_BUILTIN
  PIN4_bm, // 28 PF4/AIN14/TCB0 PWM
  PIN5_bm // 29 PF5/AIN15/TCB1 PWM
};

const uint8_t digital_pin_to_timer[] = {
  TIMERA0,      // 0 PC5/TCA0 PWM
  TIMERA0,      // 1 PC4/TCA0 PWM
  NOT_ON_TIMER, // 2 PA0/USART0_Tx/CLKIN
  NOT_ON_TIMER, // 3 PB0/USART3_Tx
  NOT_ON_TIMER, // 4 PC6
  NOT_ON_TIMER, // 5 PB1/USART3_Rx
  NOT_ON_TIMER, // 6 PB2  
  NOT_ON_TIMER, // 7 PA1/USART0_Rx
  NOT_ON_TIMER, // 8 PE3/AIN11  
  NOT_ON_TIMER, // 9 PA2/SDA
  NOT_ON_TIMER, // 10 PA3/SCL
  NOT_ON_TIMER, // 11 PE0/AIN8
  NOT_ON_TIMER, // 12 PE1/AIN9
  NOT_ON_TIMER, // 13 PE2/AIN10
  NOT_ON_TIMER, // 14 PD0/AIN0
  NOT_ON_TIMER, // 15 PD1/AIN1
  NOT_ON_TIMER, // 16 PD2/AIN2
  NOT_ON_TIMER, // 17 PD3/AIN3
  NOT_ON_TIMER, // 18 PD4/AIN4
  NOT_ON_TIMER, // 19 PD5/AIN5
  NOT_ON_TIMER, // 20 PD7/AIN7/AREF
  TIMERA0,      // 21 PC2/TCA0 PWM
  TIMERA0,      // 22 PC3/TCA0 PWM
  NOT_ON_TIMER, // 23 PA7/SS/CLKOUT
  NOT_ON_TIMER, // 24 PF0/USART2_Tx/TOSC1
  NOT_ON_TIMER, // 25 PF1/USART2_Rx/TOSC2
  NOT_ON_TIMER, // 26 PF2/AIN12  
  
  NOT_ON_TIMER, // 27 PA4/MOSI/LED_BUILTIN
#ifdef MILLIS_USE_TIMERB0
  NOT_ON_TIMER, // 28 PF4/AIN14
#else
  TIMERB0,      // 28 PF4/AIN14/TCB0 PWM
#endif
#ifdef MILLIS_USE_TIMERB1
  NOT_ON_TIMER // 29 PF5/AIN15/LED_BUILTIN
#else
  TIMERB1      // 29 PF5/AIN15/TCB1 PWM
#endif
};

#endif

void initVariant() __attribute__((weak));
void initVariant() { }

#endif
