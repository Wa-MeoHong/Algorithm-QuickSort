#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <Windows.h>

// ���� �߿��� Swap�Լ�
#define Swap(a, b) \
	{int s;\
	s = a;\
	a = b;\
	b = s;}

void _quicksort(int* Arr, int low, int high);	// ������ ���Լ�
void _patition(int* Arr, int low, int high, int& pivp);	// Pivot�� �������� ũ�� �з� �Լ�

void _fastquick(int* Arr, int low, int high);				// ������ ������ ���Լ�
void _fastpatition(int* Arr, int low, int high, int& pivp);	// Pivot�� �������� ũ�� �з� �Լ�
void _insertionS(int* Arr, int low, int high);				// ������ ���� ����( ��������) 

// �������̽� �Լ��� ���� �ζ������� �����Ͽ���
inline void QuickSort(int* Arr, int size)			// ������ �������̽� �Լ�
{
	_quicksort(Arr, 0, size - 1);			// �������̽��� ���� ���� �Լ� 
}
inline void FastQuickSort(int* Arr, int size)						// ������ ������ �������̽� �Լ�
{
	_fastquick(Arr, 0, size - 1);			// �������̽��� ���� ���� �Լ� 
}

#endif // SORTING_H
