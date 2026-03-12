# STM32 7-Segment Up/Down Counter (EXTI)

## Overview
This project is an embedded application for an STM32 microcontroller that controls a single-digit 7-segment display (0-9) using two push-buttons. Unlike polling-based approaches, this project utilizes the External Interrupt (EXTI) peripheral. One button increments the counter, while the other decrements it. Using hardware interrupts ensures the system responds instantly to button presses without wasting CPU cycles in polling loops.

## Hardware Requirements
* **Microcontroller:** STM32 Development Board (e.g., STM32F4 series).
* **Display:** Single-digit 7-segment display.
* **Input:** Two push-button switches (one for Up, one for Down).
* **Components:** Jumper wires and current-limiting resistors for the display. Pull-up or pull-down resistors for the buttons (if not utilizing the STM32's internal resistors).

## Software Architecture
This project follows a standard layered embedded architecture, introducing interrupt controllers to the stack:
* **MCAL (Microcontroller Abstraction Layer):**
    * `RCC` (Reset and Clock Control): Configures the system and peripheral clocks.
    * `GPIO` (General Purpose Input/Output): Configures the button pins as inputs and the display pins as outputs.
    * `NVIC` (Nested Vectored Interrupt Controller): Enables the specific EXTI line interrupts in the core processor.
    * `EXTI` (External Interrupt/Event Controller): Maps the GPIO pins to interrupt lines and configures the trigger conditions (e.g., rising or falling edge).
* **HAL (Hardware Abstraction Layer):**
    * `7_SEGMENT`: Custom driver handling the initialization and data output for the 7-segment display hardware.
* **LIB (Libraries):** Standard custom libraries for bitwise operations (`BIT_MATH.h`) and standard data types (`STD_TYPES.h`).

## How It Works
1.  **Initialization:** The system clock is initialized. Clocks for the target GPIO ports and the SYSCFG (System Configuration controller) are enabled. The 7-segment display is initialized and set to `0`.
2.  **Interrupt Configuration:** * Two GPIO pins are configured as inputs.
    * These pins are mapped to their respective EXTI lines.
    * The EXTI lines are configured to trigger on a specific edge (falling or rising, depending on the button circuit).
    * The corresponding EXTI interrupts are enabled in the NVIC.
3.  **Interrupt Service Routines (ISRs):** When a button is pressed, the hardware triggers the EXTI line, forcing the CPU to pause the main program and jump to the specific ISR.
    * **Up Button ISR:** Increments a global `counter` variable. If it exceeds 9, it wraps around to 0 (or caps at 9). The EXTI pending flag is cleared.
    * **Down Button ISR:** Decrements the `counter` variable. If it drops below 0, it wraps around to 9 (or caps at 0). The EXTI pending flag is cleared.
4.  **Super Loop:** The main `while(1)` loop simply takes the global `counter` value and continuously pushes it to the display using `segment_show()`, leaving the CPU free to handle the interrupts as they occur.

## Future Improvements
* Implement software-based or hardware-based debouncing (like adding a small capacitor across the buttons or checking a timer in the ISR) to prevent a single press from triggering multiple interrupts.
* Add sleep modes in the main `while(1)` loop to save power, waking the MCU only when an EXTI trigger occurs.
