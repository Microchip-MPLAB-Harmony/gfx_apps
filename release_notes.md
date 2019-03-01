# Microchip MPLAB Harmony 3 Release Notes
## GFX Apps Release v3.2.0
### NEW FEATURES


- **GFX Contents** - This GFX release consist of applications. The following table lists the contents in this GFX release.

| Category | Component | Description | Release Type | 
| --- | --- | ---- |---- |
| apps | aria_benchmark | Metrics on Aria Graphics Library | Beta |
|      | aria_mxt_configure | Example maXTouch configuration | Beta |
|      | aria_showcase | Example of Aria Graphics Library Widgets| Beta |
|      | aria_showcase_reloaded | Example of Aria Graphics Library Widgets| Beta |Beta | 
|      | aria_weather_forecast | Example weather UI | Beta |
|  doc    | | Harmony Graphics Application Documentation| Beta |


- **New Applications** - The following table provides the list of new applications.

| Application | Description | 
| --- | --- |
| aria_mxt_configure | maXTouch configuration | 
| aria_flash |  Widgets and advance capabilities|
| aria_flash (redisign) | Circular and graphing widgets| 
| aria_benchmark | Metrics on graphics operations | 

| Applications | [SAM C21N Xplained Pro Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/PartNO/ATSAMC21-XPRO) | [SAM E54 Xplained Pro Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/PartNO/ATSAME54-XPRO) | [SAM E70 Xplained Ultra Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/PartNO/ATSAME70-XPLD) | [SAM A5D2 Xplained Ultra Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/atsama5d2c-xult) |
| --- | --- | --- | --- | --- |
| aria_benchmark          |  |   | x | x |
| aria_mxt_configure      |  |   | x |   |
| aria_showcase           |  |   | x |   |
| aria_showcase_reloaded  |  |   | x |   |
| aria_weather_forecast   |  |   | x |   |

### KNOWN ISSUES

The current known issues are as follows:

* **Programming and debugging through EDBG is not supported**. The ICD4 needs to be used for programming and debugging.

* The ICD4 loads the reset line of the SAM V71 Xplained Ultra board. The following demo project drives the reset line and requires the ICD4 flex cable to be removed after programming to run the application.

| Project Name | Development Kit |
| --- | --- |
| supc\_wakeup\_rtc | SAM V71 Xplained Ultra Evaluation Kit  |
| supc\_wakeup\_rtt | SAM V71 Xplained Ultra Evaluation Kit  |
| rswdt\_timeout | SAM V71 Xplained Ultra Evaluation Kit  |
| wdt\_timeout | SAM V71 Xplained Ultra Evaluation Kit  |


### DEVELOPMENT TOOLS

| Tool | version |
| --- | --- |
| [MPLAB X IDE v5.10](https://www.microchip.com/mplab/mplab-x-ide)
         | v5.10 |
| [MPLAB XC32 C/C++ Compiler v2.15](https://www.microchip.com/mplab/compilers)      | v2.15 | 
| MPLAB X IDE plug-ins          |  |
| MPLAB Harmony Configurator (MHC)   | v3.2.0 | 
| Harmony 3 BSP (https://github.com/Microchip-MPLAB-Harmony/bsp)   | v3.2.0 |
| Harmony 3 CSP (https://github.com/Microchip-MPLAB-Harmony/csp)  | v3.2.0 |
| Harmony 3 Core (https://github.com/Microchip-MPLAB-Harmony/core)  | v3.2.0 |
| Harmony 3 GFX (https://github.com/Microchip-MPLAB-Harmony/gfx)   | v3.2.0 |
| Harmony 3 Dev_Packs (https://github.com/Microchip-MPLAB-Harmony/dev_packs)   | v3.2.0 |
| Harmony 3 USB (https://github.com/Microchip-MPLAB-Harmony/usb)   | v3.1.0 |
