#include <iostream>
#include "framework.h"
#include "Pen_Str.h"

void Change_Color(int color) {

    switch (color)
    {
    case C_RED:
        pen_Color = RGB(255, 0, 0);
        break;
    case C_GREEN:
        pen_Color = RGB(0, 255, 0);
        break;
    case C_BLUE:
        pen_Color = RGB(0, 0, 255);
        break;

    default:
        break;
    }

}