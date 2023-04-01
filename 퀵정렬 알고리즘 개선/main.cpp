/*
�̸� : �Ŵ�ȫ | �й� : 21912193
���� : ������ �˰��� ����
���� : ������ Quick Sort (������, ���ұ�ȯ����) Algorithm�� ������Ű�� �˰����� ����
�ۼ��� : 2023/03/30, ���� �ϼ��� : 2023/04/02
���� ����
	1. 1�� �⺻ �˰��� (�迭�� ù��°�� Patition���� �δ� �˰���) ����
	2. ������ �˰����� ���� (�ǹ� ���� ��� ����, ��Ƽ�� �и� ��� ����, �Ǵٸ� ������ �߰�)
	  1) �ǹ� ������ �迭�� �������� ����
	  2) �ǹ��� ���� ������ ��Ƽ�� �۾��� Hoare �˰����� ����
	  3) ���� ���� �迭�� ���� �� ���ĺ��� ȿ������ ��������(Insertion Sort)�� Ȱ����

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

	printf(" 21912193 �Ŵ�ȫ | ������ �˰��� ���� ��� ȭ��\n");
	printf(" ������ �迭�� �����ϱ⿡ ����� 1���� ������.\n\n");

	QueryPerformanceFrequency(&freq);					// CPU�� Ŭ������ ����, Ŭ������ ���� ���ϴ� ���� �ƴϹǷ� �ѹ��� ����
	int* S = GenRandArr(SIZE, 0);
	int* S_copy = copyArr(SIZE, S);
	printRArr(cout, S, SIZE); // ���� ���

	
	QueryPerformanceCounter(&t_1);					// �ð����(�Լ�������)
	QuickSort(S, SIZE); // ������ ����
	QueryPerformanceCounter(&t_2);					// �ð����(�Լ���)
	
	// ���� �ɸ� �ð� ����
	times_diff = t_2.QuadPart - t_1.QuadPart;
	times = (times_diff / (double)freq.QuadPart) * Milli; // ms���� ��ȯ
	printf("ù�� °, ������ �迭 1��°�� �����ϰ�, �����ĸ��� ����� ��� : \n");
	printf("���� �ɸ� �ð� : %.4lf ms\n\n", times);

	QueryPerformanceCounter(&t_1);					// �ð����(�Լ�������)
	//MergeQuick(S_copy, SIZE);
	FastQuickSort(S, SIZE); // ������ ����
	QueryPerformanceCounter(&t_2);					// �ð����(�Լ���)
	
	// ���� �ɸ� �ð� ����
	times_diff = t_2.QuadPart - t_1.QuadPart;
	times = (times_diff / (double)freq.QuadPart) * Milli; // ms���� ��ȯ
	printf("�ι� °, ù��°�� ����� �����ϰ�, �ٸ� ���Ĺ��� ���� ��� : \n");
	printf("���� �ɸ� �ð� : %.4lf ms\n\n", times);

	printf("���� ��� : \n");
	printRArr(cout, S, SIZE); // ���� �� ���

	delete[] S;
	delete[] S_copy;


	return 0;
}


