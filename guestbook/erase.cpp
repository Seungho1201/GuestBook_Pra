#include <iostream>
#include "framework.h"
#include "Pen_Str.h"

// �������� ����

/**
 * @brief       ȭ�� ����� �Լ�
 */
void erase(HWND hWnd)
{
    // ���� ���� �ʱ�ȭ
    test.clear();
    // �������� Ŭ���̾�Ʈ ������ ��ȿȭ�Ͽ� �ٽ� �׸��� ��û
    InvalidateRect(hWnd, NULL, TRUE); 
}