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

