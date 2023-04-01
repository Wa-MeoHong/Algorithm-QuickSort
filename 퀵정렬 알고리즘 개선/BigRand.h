#ifndef BIGRAND_H
#define BIGRAND_H

#include <iostream>
#include <iomanip>

#define Randomize() srand(time(NULL))
#define LINESIZE 10

// ���� �߿��� Swap�Լ�
#define Swap(a, b) \
	{int s;\
	s = a;\
	a = b;\
	b = s;}

using namespace std;

int* GenRandArr(int Size ,int offset);
void shuffleArr(int* RArr, int Size);
void printRArr(ostream& ostr, int* RArr, int Size);
int* copyArr(int Size, int* S);

inline int* GenRandArr(int Size, int offset)
{
	int* RandArr{ new int[Size] };		// �ſ� ���� ���� �迭�� ����� ���� �����Ҵ�

	// for���� ���� ���� ������� ���ڸ� ���� �� �������
	for (int i = 0; i < Size; i++)
	{
		RandArr[i] = i + offset;
	}
	// ���� ��
	shuffleArr(RandArr, Size);

	return RandArr;
}
inline void shuffleArr(int* RArr, int Size)
{
	int x1 = 0, x2 = 0, temp = 0, i = 0;
	Randomize();

	while (i != Size)
	{
		// �ٲ� ���� 2�� ����
		x1 = (((unsigned int)rand() << 15) | rand()) % Size;
		x2 = (((unsigned int)rand() << 15) | rand()) % Size;

		// SWAPPING
		Swap(RArr[x1], RArr[x2]);
		i++;
	}
}

inline void printRArr(ostream& ostr, int* RArr, int Size)
{
	int num_lines = 3; // 1�ٴ� 10���� ���
	int count = 0;

	if (Size <= 90)
		num_lines = Size / 10;

	for (int i = 0; i < num_lines; i++)
	{
		for (int j = 0; j < LINESIZE; j++)
		{
			ostr << setw(10) << RArr[count];	// ���, �ڸ����� 7�� ������, 7�ڸ�
			count++;
		}
		ostr << endl;						// 10�� ��� �� ����
	}

	// ���� ����� 50�̻��� �Ѵ´ٸ� 
	if (Size > 90)
	{
		ostr << "\t. . . . . . . ." << endl;		// �����ϴ� ��
		count = Size - (LINESIZE * num_lines);

		for (int i = 0; i < num_lines; i++)
		{
			for (int j = 0; j < LINESIZE; j++)
			{
				ostr << setw(10) << RArr[count];	// ���
				count++;
			}
			ostr << endl;						// ���� ����
		}
		ostr << endl;
	}

	ostr << endl;
}

inline int* copyArr(int Size, int* S)
{
	int* Copys{ new int[Size] };		// �ſ� ���� ���� �迭�� ����� ���� �����Ҵ�

	for (int i = 0; i < Size; i++)
		Copys[i] = S[i];
	return Copys;
}
#endif // !BIGRAND_H
