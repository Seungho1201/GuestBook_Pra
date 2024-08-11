#pragma once

/// ��� ���Ͽ� ����
///
/// 
#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include<vector>
#include<Windows.h>

using namespace std;

/**
 * @brief       �� ���� ������ ����ü
 * (��ǥ, �� ����, ����, �ð�, ����(LBUTTON))
*/
typedef struct Pen_Info
{
    LPARAM      Coordinate;     // ��ǥ
    int         Width;          // �� ����
    COLORREF    Color;          // �� ����
    DWORD       Time;           // �ð�
    UINT        State;          // ���� (LBUTTON)
    
} PEN_INFO;

/**
 * @brief       Pen_Info ����ü�� ���� �ڷᱸ���� �����ϱ� ���� ���� ����ü
 * ���÷��� ������� ���
*/

extern vector<PEN_INFO> test;      // ���� ���� ����
extern PEN_INFO g_Pen_Info;

extern int pen_Width;
extern COLORREF pen_Color;

#define ERASE   1000
#define REPLAY  2000
#define SAVE    3000
#define LOAD    4000

#define W_UP    5000
#define W_DOWN  6000

#define C_RED   7000
#define C_GREEN 8000
#define C_BLUE  9000
#define C_BLACK 10000




