# Inno-Maker 3.5-Inch LCD for Raspberry Pi

This repository contains setup scripts, drivers, overlays, and utilities for the Inno-Maker 3.5-inch SPI TFT LCD with capacitive touch, designed for Raspberry Pi boards. It provides everything needed to build, install, and configure the display and touch panel, including kernel modules, device tree overlays, and calibration tools.

## Product Overview

- **Product page:** [Inno-Maker 3.5" SPI Display-Capacitive Touch](https://www.inno-maker.com/product/3-5-inch-spi-display-capacitive/)
- **Resolution:** 320x480, 16-bit color
- **Touch:** Capacitive (FT6236 controller)
- **Interface:** SPI (Display), I2C (Touch), GPIO (Backlight, Reset)
- **Compatible with:** Raspberry Pi 3B+, Pi Zero, and other models

## Features

- High-speed SPI interface (up to 63Mbps)
- Capacitive touch with high accuracy
- Hardware RTC (DS3231) support
- Direct plug-on design for Raspberry Pi 40-pin header
- Includes both display and touch drivers (source code and prebuilt)
- X11 calibration and input rules for touch

## Directory Structure

- `lcd_setup/` — Setup scripts, configuration files, overlays, and rules for system integration
  - `boot/` — Boot configuration files (e.g., `cmdline.txt`, `config.txt`)
  - `etc/` — System files (e.g., `inittab`, X11 calibration configs)
  - `input_rule/` — Udev rules for touch controllers
  - `overlays/` — Device tree overlays for display and touch
  - `rtc/` — RTC setup scripts
  - `user-app/` — Touch calibration app and keyboard utility
- `source_code/` — Kernel module source code and build scripts
  - `fbtft/` — Framebuffer driver for ILI9486 LCD
  - `touch/` — FT6236 touch driver
  - `Makefile` — Build and install kernel modules and overlays

## Quick Start

### 1. Hardware Setup

1. Plug the Inno-Maker 3.5" LCD onto your Raspberry Pi’s 40-pin header.
2. (Optional) Connect the RTC battery if using the DS3231 module.

### 2. Software Setup

#### a. Build and Install Drivers (Optional, for custom kernel)

```
cd inno-maker-3.5-inch-lcd
sudo chmod -R a+rwx *
cd source_code
make
make install
```

#### b. Run the Setup Script

```
cd lcd_setup
chmod +x setup.sh
./setup.sh
```

This will:

- Backup existing drivers
- Copy overlays, udev rules, and X11 configs
- Install user applications for calibration
- Set up RTC (if present)

#### c. Reboot

```
sudo reboot
```

### 3. Calibrate Touch (Optional)

After reboot, use the calibration tool:

```
cd /home/$USER/user-app
sudo dpkg -i xinput-calibrator_0.7.5-1_armhf.deb
xinput_calibrator
```

## Resources

- [Product page](https://www.inno-maker.com/product/3-5-inch-spi-display-capacitive/)
- [Datasheet & Wiki](http://wiki.inno-maker.com/display/HOMEPAGE/3.5-inch-lcd-c)
- [Inno-Maker Support](mailto:support@inno-maker.com)

## License

Driver source code is licensed under GPLv2. See source files for details.
