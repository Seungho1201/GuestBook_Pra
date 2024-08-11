#include <iostream>
// 64비트 시간을 사용하기 위해 헤더 파일 사용
#include <windows.h>
#include "framework.h"
#include "Pen_Str.h"
#include "global_value.h"

// 스레드는 인자를 하나밖에 못받기에 HWND 전역변수는 스레드 항목에서 할당
HWND g_Hwnd;

DWORD WINAPI replay(LPVOID points)
{
    HDC hdc;
    HPEN myP, osP;

    hdc = GetDC(g_Hwnd);
    int x, y;
    
    // 요청이 바로 처리되지 않고 메세지 큐에 저장 즉 모든 작업이 끝난 후 실행
    InvalidateRect(g_Hwnd, NULL, TRUE);
    // 즉시 업데이트 요청을 보내어 모든 작업이 끝나고 실행되는 InvalidateRect 함수를 즉시 호출
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
            LineTo(hdc, x, y);  //점찍기
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

        // 리소스 자원 확보 위해 삭제
        SelectObject(hdc, osP);
        DeleteObject(myP);  // 펜을 삭제
    }
    
    ReleaseDC(g_Hwnd, hdc);
    return 0;
}