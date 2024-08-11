#pragma once

/// 모든 파일에 적용
///
/// 
#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include<vector>
#include<Windows.h>

using namespace std;

/**
 * @brief       펜 정보 관련한 구조체
 * (좌표, 펜 굵기, 색깔, 시간, 상태(LBUTTON))
*/
typedef struct Pen_Info
{
    LPARAM      Coordinate;     // 좌표
    int         Width;          // 펜 굵기
    COLORREF    Color;          // 펜 색깔
    DWORD       Time;           // 시간
    UINT        State;          // 상태 (LBUTTON)
    
} PEN_INFO;

/**
 * @brief       Pen_Info 구조체를 벡터 자료구조로 저장하기 위한 벡터 구조체
 * 리플레이 스레드시 사용
*/

extern vector<PEN_INFO> test;      // 벡터 변수 선언
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




