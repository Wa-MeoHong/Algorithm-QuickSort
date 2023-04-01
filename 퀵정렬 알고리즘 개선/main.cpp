/*
이름 : 신대홍 | 학번 : 21912193
파일 : 퀵정렬 알고리즘 개선
내용 : 기존의 Quick Sort (퀵정렬, 분할교환정렬) Algorithm을 개선시키는 알고리즘을 구상
작성일 : 2023/03/30, 최종 완성일 : 2023/04/02
수정 내역
	1. 1차 기본 알고리즘 (배열의 첫번째를 Patition으로 두는 알고리즘) 구현
	2. 개선된 알고리즘을 구현 (피벗 선정 방식 변경, 파티션 분리 방식 변경, 또다른 정렬을 추가)
	  1) 피벗 선정은 배열의 무작위로 선정
	  2) 피벗에 따라 나누는 파티션 작업은 Hoare 알고리즘을 참고
	  3) 적은 수의 배열일 때는 퀵 정렬보다 효율적인 삽입정렬(Insertion Sort)를 활용함

*/
#include "BigRand.h"
#include "Sorting.h"
#include <time.h>

#define SIZE 10000000
#define Milli 1000

int main(void)
{
	LARGE_INTEGER freq, t_1, t_2;
	double times_diff = 0, times = 0;

	printf(" 21912193 신대홍 | 퀵정렬 알고리즘 개선 결과 화면\n");
	printf(" 동일한 배열을 정렬하기에 결과는 1개만 보여줌.\n\n");

	QueryPerformanceFrequency(&freq);					// CPU의 클럭수를 측정, 클럭수는 거의 변하는 값이 아니므로 한번만 측정
	int* S = GenRandArr(SIZE, 0);
	int* S_copy = copyArr(SIZE, S);
	printRArr(cout, S, SIZE); // 먼저 출력

	
	QueryPerformanceCounter(&t_1);					// 시간재기(함수시작전)
	QuickSort(S, SIZE); // 퀵정렬 정렬
	QueryPerformanceCounter(&t_2);					// 시간재기(함수끝)
	
	// 정렬 걸린 시간 측정
	times_diff = t_2.QuadPart - t_1.QuadPart;
	times = (times_diff / (double)freq.QuadPart) * Milli; // ms단위 변환
	printf("첫번 째, 기존의 배열 1번째를 선택하고, 퀵정렬만을 사용한 방법 : \n");
	printf("정렬 걸린 시간 : %.4lf ms\n\n", times);

	QueryPerformanceCounter(&t_1);					// 시간재기(함수시작전)
	//MergeQuick(S_copy, SIZE);
	FastQuickSort(S, SIZE); // 퀵정렬 정렬
	QueryPerformanceCounter(&t_2);					// 시간재기(함수끝)
	
	// 정렬 걸린 시간 측정
	times_diff = t_2.QuadPart - t_1.QuadPart;
	times = (times_diff / (double)freq.QuadPart) * Milli; // ms단위 변환
	printf("두번 째, 첫번째의 방법을 개선하고, 다른 정렬법을 섞은 방법 : \n");
	printf("정렬 걸린 시간 : %.4lf ms\n\n", times);

	printf("정렬 결과 : \n");
	printRArr(cout, S, SIZE); // 정렬 후 출력

	delete[] S;
	delete[] S_copy;


	return 0;
}


