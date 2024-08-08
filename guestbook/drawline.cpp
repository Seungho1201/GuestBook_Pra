#include <iostream>
#include "framework.h"
#include "Pen_Str.h"

// 전역변수 정의
vector<PEN_INFO> test;
PEN_INFO g_Pen_Info;
HWND g_Hwnd;

/**
 * @brief       그리기 함수 추후 색, 굵기 기능 추가 예정
*/
void drawLine(HWND hWnd, UINT message, LPARAM lParam)
{
    static int preX, preY;
    static bool drawStart = false;
    int x, y;
    HDC hdc;

    x = LOWORD(lParam);
    y = HIWORD(lParam);
    hdc = GetDC(hWnd);

    switch (message)
    {
    case WM_LBUTTONDOWN:
        drawStart = true;

        MoveToEx(hdc, x, y, NULL);
        LineTo(hdc, x, y);

        preX = x;
        preY = y;

        g_Pen_Info.Coordinate = lParam;     // 좌표값 저장
        // g_Pen_Info.Width =
        // g_Pen_Info.color =
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
            // g_Pen_Info.Width =
            // g_Pen_Info.color =
            g_Pen_Info.Time = (DWORD)GetTickCount64();
            g_Pen_Info.State = message;
            // 벡터 구조체에 윗 자료를 저장하는 변수 추가 예정
            test.push_back(g_Pen_Info);
        }
        break;

    case WM_LBUTTONUP:
        if (drawStart)
        {
            g_Pen_Info.Coordinate = lParam;     // 좌표값 저장
            // g_Pen_Info.Width =
            // g_Pen_Info.color =
            g_Pen_Info.Time = (DWORD)GetTickCount64();
            g_Pen_Info.State = message;
            // 벡터 구조체에 윗 자료를 저장하는 변수 추가 예정
            test.push_back(g_Pen_Info);
        }
        drawStart = false;
        break;
    }
    ReleaseDC(hWnd, hdc);  // HDC 자원 해제
}