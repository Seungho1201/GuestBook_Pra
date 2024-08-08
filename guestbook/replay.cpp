#include <iostream>
// 64��Ʈ �ð��� ����ϱ� ���� ��� ���� ���
#include <windows.h>
#include "framework.h"
#include "Pen_Str.h"

// �ð��� ���� ��� ����
void replay(HWND g_Hwnd)
{
    HDC hdc;
    hdc = GetDC(g_Hwnd);
    int x, y;
    HPEN myP, osP;
    
    // ��û�� �ٷ� ó������ �ʰ� �޼��� ť�� ���� �� ��� �۾��� ���� �� ����
    InvalidateRect(g_Hwnd, NULL, TRUE);
    // ��� ������Ʈ ��û�� ������ ��� �۾��� ������ ����Ǵ� InvalidateRect �Լ��� ��� ȣ��
    UpdateWindow(g_Hwnd); 
    

    for (size_t i = 0; i < (int)test.size(); i++)
    {
        switch (test[i].State)
        {
        case WM_LBUTTONDOWN:
            x = LOWORD(test[i].Coordinate);
            y = HIWORD(test[i].Coordinate);

            MoveToEx(hdc, x, y, NULL);
            LineTo(hdc, x, y);  //�����
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

        if (i + 1 < test.size() && test[i + 1].State == WM_MOUSEMOVE)
        {
            Sleep(test[i + 1].Time - test[i].Time);
        }
    }

    ReleaseDC(g_Hwnd, hdc);

}