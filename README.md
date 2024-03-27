# SPI TFT ILI9341

Library for driving a ILI9341 TFT display with a SPI interface on Mbed OS 6.

![Display](http://www.lcdwiki.com/images/thumb/6/64/MSP2807-008.jpg/240px-MSP2807-008.jpg)

Original library by [Peter Drescher](https://os.mbed.com/users/dreschpe/code/SPI_TFT_ILI9341/).
Forked from edit by [Michael Ammann](https://os.mbed.com/users/mazgch/code/SPI_TFT_ILI9341/).

Minor change of `wait_ms` to `ThisThread::sleep_for` to work with Mbed OS 6.

I will add various graphics components and examples in the future.

## Graphics components

\* = from original library

- [x] Line*
- [x] Rectangle/Filled Rectangle*
- [x] Circle/Filled Circle*
- [x] Text*
- [x] Bitmap*
- [x] Progress Bar

## Examples

### Setup

```cpp
#include "mbed.h"
#include "SPI_TFT_ILI9341.h"
#include "ProgressBar.h"

PinName csPin(ARDUINO_UNO_D9);
PinName resetPin(ARDUINO_UNO_D1);
PinName dcPin(ARDUINO_UNO_D10);
PinName mosiPin(ARDUINO_UNO_D11);
PinName sckPin(ARDUINO_UNO_D13);
PinName misoPin(ARDUINO_UNO_D12);

SPI_TFT_ILI9341 display(mosiPin, misoPin, sckPin, csPin, resetPin, dcPin);
```

### Progress Bar

```cpp
/// ...setup first

// Using display.height() since display is rotated
ProgressBar bar(display, 5, 5, display.height() - 5, 16);

// Get a random float between 0.0 and 1.0
float getRandomFloat() {
    return static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
}

// main() runs in its own thread in the OS
int main()
{
    // Setup display
    display.set_orientation(1);
    display.foreground(White);
    display.background(Black);
    display.cls();

    // Setup progress bar
    bar.setup();
    // Randomly set progress bar percentage
    while (true) {
        bar.setProgressPercentage(getRandomFloat());
        ThisThread::sleep_for(500ms);
    }
}
```
