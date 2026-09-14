# Smart Home Automation System Firmware

This repository contains the firmware for a smart home automation system developed using a Model-Based Design approach with MATLAB Simulink and an STM32 microcontroller. The system automates lighting, heating simulation, and window blinds, employing a V-Model development methodology for robust testing and validation.

## Project Overview

* **Authors:** Alessandro Maruotto and Sabato Paolillo (Group 31).
* **Goal:** Manage residential automation features including a servo-controlled blind, relay-actuated lighting, and PWM-modulated temperature feedback.

## Key Features

* **Smart Lighting:** Manual toggle and timed activation (configurable between 5 and 30 seconds) utilizing a 5V relay.
* **Temperature Simulation:** Regulates simulated ambient temperature from 16°C to 30°C, providing visual feedback through an RGB LED mapped to five distinct color tiers via PWM.
* **Automated Blinds:** Controls an SG90 servo motor from 0° (closed) to 180° (open) in 20° discrete steps based on specific PWM duty cycle adjustments.
* **UART Communication:** Allows parameter configuration via serial terminal and transmits system status updates every 10 seconds during operation.
* **State Machine Logic:** Organizes system behavior into clear states: INATTIVO (Inactive), CONFIGURAZIONE (Configuration), and OPERAZIONE (Operation).

## Hardware Components

* STM32G474RET3 Nucleo Board.
* 1x SG90 Servo Motor.
* 1x 5V Relay Module.
* 1x RGB LED and 1x Yellow User LED.
* 4x Push Buttons (ATTIVA, CONFIG, LUCI, LUCI\_TMP).

## Software \& Tools

* MATLAB / Simulink / Stateflow (Model-Based Design).
* STMicroelectronics STM32CubeMX (Pin, LPUART, and Timer configuration).
* PuTTY (Serial UART terminal configured at 115200 baud, 8 data bits, 1 stop bit, no parity).

## Installation \& Usage

1. Wire the components according to the GPIO mapping: Servo to PB6, Relay to PC2, RGB LED to PA6/PC7/PC9, and user buttons to PC13/PB0/PC10/PA15.
2. Flash the Simulink-generated C code onto the STM32 board.
3. Open PuTTY and connect to the respective COM port.
4. Press the **ATTIVA** button to wake the device from its INATTIVO state.
5. Follow the on-screen UART prompts to perform the mandatory initial configuration (blinds angle, lighting mode, timer duration, and temperature).
6. Press **CONFIG** to lock in the parameters and enter OPERAZIONE mode, where all automated features execute in parallel and the user LED blinks at 2 Hz.

