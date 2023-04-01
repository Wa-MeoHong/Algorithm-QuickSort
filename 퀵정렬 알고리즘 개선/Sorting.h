#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <Windows.h>

// 가장 중요한 Swap함수
#define Swap(a, b) \
	{int s;\
	s = a;\
	a = b;\
	b = s;}

void _quicksort(int* Arr, int low, int high);	// 퀵정렬 본함수
void _patition(int* Arr, int low, int high, int& pivp);	// Pivot을 기준으로 크기 분류 함수

void _fastquick(int* Arr, int low, int high);				// 개선된 퀵정렬 본함수
void _fastpatition(int* Arr, int low, int high, int& pivp);	// Pivot을 기준으로 크기 분류 함수
void _insertionS(int* Arr, int low, int high);				// 실제로 사용된 정렬( 삽입정렬) 

// 인터페이스 함수는 따로 인라인으로 구현하였음
inline void QuickSort(int* Arr, int size)			// 퀵정렬 인터페이스 함수
{
	_quicksort(Arr, 0, size - 1);			// 인터페이스로 들어가기 위한 함수 
}
inline void FastQuickSort(int* Arr, int size)						// 개선된 퀵정렬 인터페이스 함수
{
	_fastquick(Arr, 0, size - 1);			// 인터페이스로 들어가기 위한 함수 
}

#endif // SORTING_H
