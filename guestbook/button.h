#pragma once

#include <windows.h>  // CreateWindow�� �ʿ��� ���


class Button {
private:
    int x;                // ��ư�� x ��ġ
    int y;                // ��ư�� y ��ġ
    int weight;           // ��ư�� ��
    int height;           // ��ư�� ����
    int func;             // ��ư�� ID
    LPCWSTR text;         // ��ư �ؽ�Ʈ

    HWND c_Hwnd;          // �θ� ������ �ڵ�
public:

    /**
 * @brief       ��ư ���� ������ (x, y, �ʺ�, ����, ���, ��ư �� �ؽ�Ʈ)
*/
    Button(int x, int y, int weight, int height, int func, LPCWSTR text);

    // ��ư ���� �޼���
    void mkButton(HWND g_Hwnd);
};
