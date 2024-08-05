#include <iostream>
#include "framework.h"
#include "Pen_Str.h"

// 시간도 같이 계산 예정
void replay(HWND g_Hwnd)
{
    HDC hdc;
    hdc = GetDC(g_Hwnd);
    int x, y;
    HPEN myP, osP;

    myP = CreatePen(PS_SOLID, 10, RGB(255, 255, 255));
    osP = (HPEN)SelectObject(hdc, myP);

    for (size_t i = 0; i < (int)test.size(); i++)
    {
        switch (test[i].State)
        {
        case WM_LBUTTONDOWN:
            x = LOWORD(test[i].Coordinate);
            y = HIWORD(test[i].Coordinate);

            MoveToEx(hdc, x, y, NULL);
            LineTo(hdc, x, y + 1);  //점찍기
            break;

        case WM_MOUSEMOVE:
            LineTo(hdc, LOWORD(test[i].Coordinate), HIWORD(test[i].Coordinate));
            break;

        case WM_LBUTTONUP:
            LineTo(hdc, LOWORD(test[i].Coordinate), HIWORD(test[i].Coordinate));
            break;

        default:
            break;
        }

    }

    SelectObject(hdc, osP);

    for (size_t i = 0; i < (int)test.size(); i++)
    {
        switch (test[i].State)
        {
        case WM_LBUTTONDOWN:
            x = LOWORD(test[i].Coordinate);
            y = HIWORD(test[i].Coordinate);

            MoveToEx(hdc, x, y, NULL);
            LineTo(hdc, x, y + 1);  //점찍기
            break;

        case WM_MOUSEMOVE:
            LineTo(hdc, LOWORD(test[i].Coordinate), HIWORD(test[i].Coordinate));
            break;

        case WM_LBUTTONUP:
            LineTo(hdc, LOWORD(test[i].Coordinate), HIWORD(test[i].Coordinate));
            break;

        default:
            break;
        }

        Sleep(1);
    }

    ReleaseDC(g_Hwnd, hdc);

}