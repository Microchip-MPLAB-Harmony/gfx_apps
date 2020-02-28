# Microchip MPLAB® Harmony 3 Graphics Release Notes
## Graphics Apps Release v3.6.0

- **Graphics Contents** - This Graphics release consists of applications. The following table lists the contents in this Graphics release.

**Legato graphics library** - the performance improved graphics library for MPLAB Harmony Graphics Suite. Supports PIC32 and SAM microcontrollers.

| Category | Item | Description | Release Type |
| --- | --- | ---- |---- |
| apps | legato_benchmark | Metrics on Legato graphics library | Beta |
| | legato_monitor | Example blood pressure application| Beta |
| | legato_showcase | Example of Legato graphics library widgets| Beta |
| | legato_adventure | Example of simple sprite animation| Beta |
| | legato_cooker | Example of professional cooking appliance UI | Beta |

**Aria graphics library** - the feature-complete production library within MPLAB Harmony Graphics Suite. Supports PIC32 and SAM microcontrollers and microprocessors.

| Category | Item | Description | Release Type |
| --- | --- | ---- |---- |
| apps | aria_benchmark | Metrics on Aria graphics library | Production |
| | aria_dashboard | Example automobile dashboard demonstration| Production |
| | aria_image_viewer| Image viewing and gesture movements| Production |
| | aria_infotainment| Example vehicle infotainment system| Production |
| | aria_mxt_configure | Example maXTouch configuration | Production |
| | aria_oven_controller | Example SRAM-only GPU demonstration| Production |
| | aria_showcase | Example of Aria graphics library widgets| Production |
| | aria_showcase_reloaded | Example of Aria graphics library widgets| Production |
| | aria_thermostat | Example thermostat UI demonstration | Production |
| | aria_weather_forecast | Example weather UI demonstration| Production |

**Misc items** - items associated with the entire graphics suite.

| Category | Item | Description | Release Type |
| --- | --- | ---- |---- |
| doc | Help | Application Help Documentation| Beta |
| docs| Help | Application Help Documentation HTML| Beta |

### Bug fixes and library updates for v3.6.0

- **New Applications** - The following table provides the list of new applications.

| Application | Description |
| --- | --- |
| legato_adventure | MH3-24650 Paralax fun demonstration|
| legato_cooker | MH3-28758 Useful cooking UI demonstration |

- **Development kit and demo application support** - The following table provides the list of applications for different development kits.

| Applications | [SAM E54 Curiosity Ultra](https://www.microchip.com/Developmenttools/ProductDetails/DM320210) | [SAM E70 Xplained Ultra](https://www.microchip.com/developmenttools/ProductDetails/PartNO/ATSAME70-XPLD) | [SAM A5D2 Xplained Ultra](https://www.microchip.com/developmenttools/ProductDetails/atsama5d2c-xult) |[Multimedia Expansion Board II EF](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/DM320005-5) | [Multimedia Expansion Board II DA](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/DM320005-5) |[SAM9X60-EK Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/DT100126)|[Curiosity PIC32MZ EF 2.0](https://www.microchip.com/Developmenttools/ProductDetails/DM320209) |
| --- | --- | --- | --- | --- | --- | --- | -- |
| aria_adventure          |   |   |   |   | x | | |
| aria_benchmark          | x | x | x |   | x | x | |
| aria_dashboard          |   |   | x |   | x | x | |
| aria_image_viewer       |   |   |   |   | x |   | |
| aria_infotainment       |   |   |   |   | x | | |
| aria_mxt_configure      |   |   |   |   | x | | |
| aria_oven_controller    |   | x |   |   | x | | |
| aria_radial_menu        |   |   |   |   | x | | |
| aria_showcase           |   | x |   |   | x | | |
| aria_showcase_reloaded  |   | x |   |   | x | | |
| aria_thermostat         |   |   |   |   | x | |x |
| aria_weather_forecast   |   | x |   |   | x | | |
| legato_adventure        | x | x |   |   | x | | |
| legato_benchmark        | x | x |   |   |   | | |
| legato_monitor          | x |   |   |   |   | | |
| legato_showcase         | x |   |   |   |   | | |
| legato_cooker           | x |   |   |   |   | | |

### KNOWN ISSUES

The current known issues are as follows:

* Code is compliant to MISRA C 2012 Mandatory guidelines, with the exception of Rule 9.1 (Code 530).
In gfx.c, the variable args is falsely detected in violation of Code 530: &quot;Symbol not initialized&quot; at line 358.  In fact, va_start at line 358 is exactly where args is initialized.

* When regenerating demo applications, keep all code between comments “//CUSTOM CODE…” and “//END OF CUSTOM CODE…”. Custom code is added to perform specific functionality.
* Applications running on SAM E70 in combination with LCC will observe visual rendering artifacts on display during SD card R/W access. There is no loss in SD Card data.
* FreeRTOS osal has an incorrect include path that causes build failures in non-Windows environments.
* SAM E54/D51 must be debugged using MPLABX v5.25
* For a list of current issues that affect this release, refer to MPLAB Harmony [GFX Issues and Errata](https://github.com/Microchip-MPLAB-Harmony/gfx/wiki/Issues-and-Errata)

### DEVELOPMENT TOOLS

| Tool | Version |
| --- | --- |
| [MPLAB® X IDE](https://www.microchip.com/mplab/mplab-x-ide) | v5.30 |
| [MPLAB® XC32 C/C++ Compiler](https://www.microchip.com/mplab/compilers)      | v2.40 |
| MPLAB® X IDE plug-ins          |  |
| MPLAB® Harmony Configurator (MHC) plug-in   | v3.3.1 |
| [Harmony 3 BSP](https://github.com/Microchip-MPLAB-Harmony/bsp)   | v3.6.0 |
| [Harmony 3 CSP](https://github.com/Microchip-MPLAB-Harmony/csp)  | v3.6.0 |
| [Harmony 3 Core](https://github.com/Microchip-MPLAB-Harmony/core)  | v3.6.0 |
| [Harmony 3 Graphics ](https://github.com/Microchip-MPLAB-Harmony/gfx)   | v3.6.0 |
| [Harmony 3 Dev_Packs](https://github.com/Microchip-MPLAB-Harmony/dev_packs)   | v3.6.0 |
| [Harmony 3 USB](https://github.com/Microchip-MPLAB-Harmony/usb)   | v3.4.0 |
| [Harmony 3 CMSIS-FreeRTOS](https://github.com/ARM-software/CMSIS-FreeRTOS)   | v10.2.0 |
| [IAR Embedded WorkBench ARM](https://www.iar.com/iar-embedded-workbench/#!?architecture=Arm)   | v8.40.1 |
