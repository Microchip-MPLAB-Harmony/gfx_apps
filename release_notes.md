# Microchip MPLAB® Harmony 3 Graphics Release Notes
## Graphics Apps Release v3.3.0
### NEW FEATURES


- **Graphics Contents** - This Graphics release consist of applications. The following table lists the contents in this Graphics release.

| Category | Component | Description | Release Type | 
| --- | --- | ---- |---- |
| apps | aria_benchmark | Metrics on Aria Graphics Library | Beta |
|      | aria_dashboard | Example automobile dashboard demo| Beta |
|      | aria_image_viewer| Image viewing and gesture movements| Beta |
|      | aria_infotainment| Example vehicle infotainment system| Beta |
|      | aria_mxt_configure | Example maXTouch configuration | Beta |
|      | aria_oven_controller | Example SRAM-only GPU demo| Beta |
|      | aria_showcase | Example of Aria Graphics Library Widgets| Beta |
|      | aria_showcase_reloaded | Example of Aria Graphics Library Widgets| Beta |Beta | 
|      | aria_weather_forecast | Example weather UI | Beta |
|  doc | API | Harmony Graphics Application API Documentation| Beta |
|  docs| Help | Harmony Graphics Application Help Documentation| Beta |

- **New Applications** - The following table provides the list of new applications.

| Application | Description | 
| --- | --- |
| aria_dashboard | Example automobile dashboard demo | 
| aria_image_viewer|  Example viewing and gesture movement demo|
| aria_infotainment|  Example infotainment system demo|
| aria_oven_controller |  Example SRAM-only GPU demo |

- **Development kit and demo application support** - The following table provides the list of applications for different development kits.

| Applications | [SAM C21N Xplained Pro Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/PartNO/ATSAMC21-XPRO) | [SAM E54 Xplained Pro Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/PartNO/ATSAME54-XPRO) | [SAM E70 Xplained Ultra Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/PartNO/ATSAME70-XPLD) | [SAM A5D2 Xplained Ultra Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/atsama5d2c-xult) |[Multimedia Expansion Board II](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/DM320005-5) |
| --- | --- | --- | --- | --- | --- |
| aria_dashboard          |  |   |   | x |   |
| aria_benchmark          |  |   | x | x | x |
| aria_image_viewer       |  |   |   |   | x |
| aria_infotainment       |  |   |   |   | x |
| aria_benchmark          |  |   | x | x | x |
| aria_mxt_configure      |  |   | x |   |   |
| aria_oven_controller    |  |   | x |   | x |
| aria_showcase           |  |   | x |   |   |
| aria_showcase_reloaded  |  |   | x |   |   |
| aria_weather_forecast   |  |   | x |   |   |

### KNOWN ISSUES

The current known issues are as follows:

* Applications are compliant to MISRA C 2012 Mandatory guidelines, except for Rules R.9.1 and R.17.3

* Applications for PIC32MZ DA using external DDR are only supported on Rev B0 silicon.

### DEVELOPMENT TOOLS

| Tool | Version |
| --- | --- |
| [MPLAB® X IDE](https://www.microchip.com/mplab/mplab-x-ide) | v5.20 |
| [MPLAB® XC32 C/C++ Compiler](https://www.microchip.com/mplab/compilers)      | v2.20 | 
| MPLAB® X IDE plug-ins          |  |
| MPLAB® Harmony Configurator (MHC) plug-in   | v3.3.0 | 
| [Harmony 3 BSP](https://github.com/Microchip-MPLAB-Harmony/bsp)   | v3.3.0 |
| [Harmony 3 CSP](https://github.com/Microchip-MPLAB-Harmony/csp)  | v3.3.0 |
| [Harmony 3 Core](https://github.com/Microchip-MPLAB-Harmony/core)  | v3.3.0 |
| [Harmony 3 Graphics ](https://github.com/Microchip-MPLAB-Harmony/gfx)   | v3.3.0 |
| [Harmony 3 Dev_Packs](https://github.com/Microchip-MPLAB-Harmony/dev_packs)   | v3.3.0 |
| [Harmony 3 USB](https://github.com/Microchip-MPLAB-Harmony/usb)   | v3.2.0 |
