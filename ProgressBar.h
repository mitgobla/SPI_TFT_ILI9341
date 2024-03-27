// Class that represents a drawable progress bar.
// Written by Ben Dodd (mitgobla)

#ifndef MBED_PROGRESSBAR_H
#define MBED_PROGRESSBAR_H

#include "mbed.h"
#include "SPI_TFT_ILI9341.h"

class ProgressBar {
public:

    ProgressBar(SPI_TFT_ILI9341& display, int x0, int y0, int x1, int y1, int foregroundColor = Green, int backgroundColor = Black, int borderColor = White);
    void setForegroundColor(int foregroundColor);
    void setBackgroundColor(int backgroundColor);
    void setBorderColor(int borderColor);

    void setup();
    void setProgressPercentage(float percentage);

private:
    SPI_TFT_ILI9341& _display;
    int _x0, _y0;
    int _x1, _y1;
    int _fgColor, _bgColor, _bdColor;

    int _value;
};

#endif