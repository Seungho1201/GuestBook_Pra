#include <iostream>
#include "framework.h"
#include "Pen_Str.h"

// 전역변수 정의
vector<PEN_INFO> test;
PEN_INFO g_Pen_Info;

// 펜 기본 굵기 10
int pen_Width = 10;
COLORREF pen_Color = RGB(0, 0, 0);
// HWND g_Hwnd;

/**
 * @brief       그리기 함수 추후 색, 굵기 기능 추가 예정
*/
void drawLine(HWND hWnd, UINT message, LPARAM lParam)
{
    static int preX, preY;
    static bool drawStart = false;
    int x, y;
    HDC hdc;
    HPEN myP, osP;
    
    x = LOWORD(lParam);
    y = HIWORD(lParam);
    hdc = GetDC(hWnd);

    myP = CreatePen(PS_SOLID, pen_Width, pen_Color);
    osP = (HPEN)SelectObject(hdc, myP);


    switch (message)
    {
    case WM_LBUTTONDOWN:
        drawStart = true;

        MoveToEx(hdc, x, y, NULL);
        LineTo(hdc, x, y);

        preX = x;
        preY = y;

        g_Pen_Info.Coordinate = lParam;     // 좌표값 저장
        g_Pen_Info.Width = pen_Width ;
        g_Pen_Info.Color = pen_Color;
        g_Pen_Info.Time = (DWORD)GetTickCount64();
        g_Pen_Info.Time = (DWORD)GetTickCount64();
        g_Pen_Info.State = message;

        // 벡터 구조체에 윗 자료를 저장하는 변수 추가 예정
        test.push_back(g_Pen_Info);
        break;

    case WM_MOUSEMOVE:
        if (drawStart)
        {
            MoveToEx(hdc, preX, preY, NULL);
            LineTo(hdc, x, y);

            preX = x;
            preY = y;

            g_Pen_Info.Coordinate = lParam;     // 좌표값 저장
            g_Pen_Info.Width = pen_Width;
            g_Pen_Info.Color = pen_Color;
            g_Pen_Info.Time = (DWORD)GetTickCount64();
            g_Pen_Info.State = message;

            // 벡터 구조체에 윗 구조체 데이터 저장
            test.push_back(g_Pen_Info);
        }
        break;

    case WM_LBUTTONUP:
        if (drawStart)
        {
            g_Pen_Info.Coordinate = lParam;     // 좌표값 저장
            g_Pen_Info.Width = pen_Width;
            g_Pen_Info.Color = pen_Color;
            g_Pen_Info.Time = (DWORD)GetTickCount64();
            g_Pen_Info.State = message;
            // 벡터 구조체에 윗 구조체 데이터 저장
            test.push_back(g_Pen_Info);
        }
        drawStart = false;
        break;
    }

    SelectObject(hdc, osP);
    DeleteObject(myP);  // 펜을 삭제

    ReleaseDC(hWnd, hdc);  // HDC 자원 해제
}