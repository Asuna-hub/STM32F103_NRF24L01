<div align="center">

# STM32F103 NRF24L01 Project 🇺🇸 🇷🇺

[English](#english) | [Русский](#russian)

</div>

<a name="english"></a>
## 🇺🇸 English Version

### Project Goal
Implementing reliable wireless communication between multiple devices using NRF24L01 modules based on STM32F103C8T6 microcontroller.

### 📋 Description
This project provides a complete driver for NRF24L01 wireless transceiver modules working with STM32F103C8T6 (Blue Pill board). The implementation includes robust error handling, power management, and easy-to-use API for embedded applications.

### 🛠 Hardware
- **MCU**: STM32F103C8T6 (Blue Pill)
- **Wireless Module**: NRF24L01+
- **IDE**: Keil uVision 5
- **Toolchain**: ARM Compiler Version 6
- **Debugger**: ST-Link V2
- **Communication**: SPI 1

### ✨ Features
- 🔄 **Bidirectional communication** - Support for both transmitter and receiver modes
- 📶 **Multiple data rates** - 250kbps, 1Mbps, 2Mbps
- 🔋 **Power management** - Low power modes support
- 🛡 **Error detection** - CRC and automatic retransmission
- 📡 **Multi-channel** - 125 RF channels support
- 🔌 **Easy configuration** - Simple API for quick setup

### 🚀 Quick Start

#### 1. Clone Repository
```bash
git clone https://github.com/Asuna-hub/STM32F103_NRF24L01.git
cd STM32F103_NRF24L01
