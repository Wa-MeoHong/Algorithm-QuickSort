#ifndef BIGRAND_H
#define BIGRAND_H

#include <iostream>
#include <iomanip>

#define Randomize() srand(time(NULL))
#define LINESIZE 10

// 가장 중요한 Swap함수
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
	int* RandArr{ new int[Size] };		// 매우 많은 수의 배열을 만들기 위해 동적할당

	// for문을 통해 먼저 순서대로 숫자를 생성 후 집어넣음
	for (int i = 0; i < Size; i++)
	{
		RandArr[i] = i + offset;
	}
	// 섞어 줌
	shuffleArr(RandArr, Size);

	return RandArr;
}
inline void shuffleArr(int* RArr, int Size)
{
	int x1 = 0, x2 = 0, temp = 0, i = 0;
	Randomize();

	while (i != Size)
	{
		// 바꿀 숫자 2개 선정
		x1 = (((unsigned int)rand() << 15) | rand()) % Size;
		x2 = (((unsigned int)rand() << 15) | rand()) % Size;

		// SWAPPING
		Swap(RArr[x1], RArr[x2]);
		i++;
	}
}

inline void printRArr(ostream& ostr, int* RArr, int Size)
{
	int num_lines = 3; // 1줄당 10개만 출력
	int count = 0;

	if (Size <= 90)
		num_lines = Size / 10;

	for (int i = 0; i < num_lines; i++)
	{
		for (int j = 0; j < LINESIZE; j++)
		{
			ostr << setw(10) << RArr[count];	// 출력, 자리수를 7로 지정해, 7자리
			count++;
		}
		ostr << endl;						// 10개 출력 후 엔터
	}

	// 만약 사이즈가 50이상이 넘는다면 
	if (Size > 90)
	{
		ostr << "\t. . . . . . . ." << endl;		// 생략하는 것
		count = Size - (LINESIZE * num_lines);

		for (int i = 0; i < num_lines; i++)
		{
			for (int j = 0; j < LINESIZE; j++)
			{
				ostr << setw(10) << RArr[count];	// 출력
				count++;
			}
			ostr << endl;						// 한줄 띄우기
		}
		ostr << endl;
	}

	ostr << endl;
}

inline int* copyArr(int Size, int* S)
{
	int* Copys{ new int[Size] };		// 매우 많은 수의 배열을 만들기 위해 동적할당

	for (int i = 0; i < Size; i++)
		Copys[i] = S[i];
	return Copys;
}
#endif // !BIGRAND_H
