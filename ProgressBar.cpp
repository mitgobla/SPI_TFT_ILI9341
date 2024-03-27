// Class that represents a drawable progress bar.
// Written by Ben Dodd (mitgobla)

#include "ProgressBar.h"

ProgressBar::ProgressBar(SPI_TFT_ILI9341& display, int x0, int y0, int x1, int y1, int foregroundColor, int backgroundColor, int borderColor) :
    _display(display), _x0(x0), _y0(y0), _x1(x1), _y1(y1), _fgColor(foregroundColor), _bgColor(backgroundColor), _bdColor(borderColor) {}

void ProgressBar::setForegroundColor(int foregroundColor) {
    _fgColor = foregroundColor;
}

void ProgressBar::setBackgroundColor(int backgroundColor) {
    _bgColor = backgroundColor;
}

void ProgressBar::setBorderColor(int borderColor) {
    _bdColor = borderColor;
}

void ProgressBar::setup() {
    _display.rect(_x0, _y0, _x1, _y1, _bdColor);
    _display.fillrect(_x0 + 1, _y0 + 1, _x1 - 1, _y1 - 1, _bgColor);
}

void ProgressBar::setProgressPercentage(float percentage) {
    int maxValue = _x1 - 1;
    int minValue = _x0 + 1;

    _value = static_cast<int>(std::round(minValue + (maxValue - minValue) * percentage));
    for (int x = _x0 + 1; x <= (_x1 - 1); x++) {
        if (x <= _value) {
            _display.line(x, _y0 + 1, x, _y1 - 1, _fgColor);
        }
        if (x < (_x1 - 1) && x > _value) {
            _display.line(x + 1, _y0 + 1, x + 1, _y1 - 1, _bgColor);
        }
    }
}