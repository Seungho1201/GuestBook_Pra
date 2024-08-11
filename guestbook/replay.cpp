#include <iostream>
// 64��Ʈ �ð��� ����ϱ� ���� ��� ���� ���
#include <windows.h>
#include "framework.h"
#include "Pen_Str.h"
#include "global_value.h"

// ������� ���ڸ� �ϳ��ۿ� ���ޱ⿡ HWND ���������� ������ �׸񿡼� �Ҵ�
HWND g_Hwnd;

DWORD WINAPI replay(LPVOID points)
{
    HDC hdc;
    HPEN myP, osP;

    hdc = GetDC(g_Hwnd);
    int x, y;
    
    // ��û�� �ٷ� ó������ �ʰ� �޼��� ť�� ���� �� ��� �۾��� ���� �� ����
    InvalidateRect(g_Hwnd, NULL, TRUE);
    // ��� ������Ʈ ��û�� ������ ��� �۾��� ������ ����Ǵ� InvalidateRect �Լ��� ��� ȣ��
    UpdateWindow(g_Hwnd); 
    

    for (size_t i = 0; i < (int)test.size(); i++)
    {

        myP = CreatePen(PS_SOLID, test[i].Width, test[i].Color);
        osP = (HPEN)SelectObject(hdc, myP);

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

        // ���ҽ� �ڿ� Ȯ�� ���� ����
        SelectObject(hdc, osP);
        DeleteObject(myP);  // ���� ����
    }
    
    ReleaseDC(g_Hwnd, hdc);
    return 0;
}