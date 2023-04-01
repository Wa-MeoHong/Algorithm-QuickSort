# include "Sorting.h"

// 퀵정렬 본 함수
void _quicksort(int* Arr, int low, int high)
{
	// 처음 피벗포인터를 인덱스 0으로 지정( 배열 맨 처음 ) 
	int Pivot_P = 0;
	if (high > low)
	{
		_patition(Arr, low, high, Pivot_P); // 피벗을 기준으로 왼쪽은 작은, 오른쪽은 큰값으로 분리
		_quicksort(Arr, low, Pivot_P - 1); // 왼쪽 배열 
		_quicksort(Arr, Pivot_P + 1, high); // 오른쪽 배열
	}
}
// Pivot을 기준으로 크기별로 분류하는 함수
void _patition(int* Arr, int low, int high, int& pivp)
{
	int i = 0, j = low;
	int Piv_item = Arr[low];				// 피벗을 Arr의 맨처음으로 잡는다.
	for (i = low + 1; i <= high; i++) {		// i는 2번째 원소부터, 배열 끝까지 갈 때까지
		if (Arr[i] < Piv_item)				// 만약 Pivot보다 작다면 
		{
			++j;							// j를 한칸 띄운 후, 
			Swap(Arr[i], Arr[j]);			// i와 j를 바꾼다.
		}
	}
	// 마지막 i에 다다르고 난 후, 분할이 완료되었음
	pivp = j; // 현재 j의 위치가 pivot의 위치가 되어야 하므로 바뀜
	// 기준이 되었던 첫번째 값과 들어갈 위치의 값과 바꿈
	//(크기는 pivot이 들어갈 자리의 값보다 pivot이 더 큼) 
	Swap(Arr[low], Arr[pivp]);
}

// 개선된 정렬 중 퀵정렬 부분
void _fastquick(int* Arr, int low, int high)		// 개선된 퀵정렬 본함수
{
	int P_Point = 0;
	
	if (high - low > 20) // 배열 20개만 남았을 시, 이 과정을 거치지 않게 됨
	{
		_fastpatition(Arr, low, high, P_Point);		// 피벗을 기준으로 나눔
		_fastquick(Arr, low, P_Point - 1);			// 피벗보다 작은 배열
		_fastquick(Arr, P_Point + 1, high);		// 피벗보다 큰 배열
	}	
	else if (low < high)
	// 만약, 배열의 크기가 충분히 작고, low가 high보다 작은 정상적인 상태라면
	{
		_insertionS(Arr, low, high);			// 삽입정렬을 통한 정렬로 한다.
	}
}
void _fastpatition(int* Arr, int low, int high, int& pivp)
{
	int P_Item = 0;		// 피벗값
	int i = low + 1, j = high;	// 피벗은 맨처음으로 밀어넣고 나머지를 비교

	// 피벗의 값은 무작위로 선정한다. (인덱스를 무작위로 선정해서 구현)
	int R = ((((unsigned int)rand() << 15) | rand()) % (high - low)) + low;
	P_Item = Arr[R];	
	Swap(Arr[low], Arr[R]);		// 선정한 Pivot을 먼저 맨 앞으로 옮겨 분류에서 자유롭게 함

	// i는 피벗보다 작은 값을 가져야하고,
	// j는 피벗보다 큰값만을 가지게 된다.
	while(1)
	{
		// 피벗보다 큰 i를 찾고,
		while (Arr[i] < P_Item)
			++i;
		// 피벗보다 작은 j를 찾는다.
		while (Arr[j] > P_Item)
			--j;

		// 만약 j가 i의 값을 넘겨 작아지게 되면 탐색을 멈춤
		if (i > j)
			break;

		// 모두 찾았으면 i와 j의 값을 Swapping
		Swap(Arr[i], Arr[j]);
	}
	// j가 바로 피벗의 위치가 되므로, 피벗과 j값을 바꿈
	pivp = j;
	Swap(Arr[j], Arr[low]);
}
void _insertionS(int* Arr, int low, int high)
{
	int i = low + 1, j = 0;			// i는 처음 시작은 low + 1부터 시작함
	// 이유는 배열의 원소 최소 2개를 비교하고, 중간에 삽입하기 때문
	int key = 0;

	while (i < high)			// i가 high가 될 때까지
	{
		key = Arr[i];			// key는 i의 위치의 값. (처음은 low+1)
		for (j = i - 1; j >= 0 && Arr[j] > key; j--)
			Arr[j + 1] = Arr[j];		
			// 만약, j의 값이 key보다 크다면, key를 집어넣을 공간을 만들기 위해 한칸 뒤로 미룸
		// 반복하다가 결국, j가 들어갈 자리를 찾아내고, j가 앞으로 한칸 더 나아감.
		Arr[j + 1] = key; // 따라서 j +1 의 값을 집어넣게 됨.
		i++;	//i++ 함.
	}
}

void _selectionS(int* Arr, int low, int high)
{
	int min_v = 0, min_index = low;

	for (int j = low; j <= high-1; j++)
	{
		min_index = j;
		min_v = Arr[j];

		for (int i = j + 1; i <= high; i++)
		{
			if (min_v > Arr[i])
			{
				min_v = Arr[i];
				min_index = i;
			}
		}
		Swap(Arr[min_index], Arr[j]);
	}
}
