# include "Sorting.h"

// ������ �� �Լ�
void _quicksort(int* Arr, int low, int high)
{
	// ó�� �ǹ������͸� �ε��� 0���� ����( �迭 �� ó�� ) 
	int Pivot_P = 0;
	if (high > low)
	{
		_patition(Arr, low, high, Pivot_P); // �ǹ��� �������� ������ ����, �������� ū������ �и�
		_quicksort(Arr, low, Pivot_P - 1); // ���� �迭 
		_quicksort(Arr, Pivot_P + 1, high); // ������ �迭
	}
}
// Pivot�� �������� ũ�⺰�� �з��ϴ� �Լ�
void _patition(int* Arr, int low, int high, int& pivp)
{
	int i = 0, j = low;
	int Piv_item = Arr[low];				// �ǹ��� Arr�� ��ó������ ��´�.
	for (i = low + 1; i <= high; i++) {		// i�� 2��° ���Һ���, �迭 ������ �� ������
		if (Arr[i] < Piv_item)				// ���� Pivot���� �۴ٸ� 
		{
			++j;							// j�� ��ĭ ��� ��, 
			Swap(Arr[i], Arr[j]);			// i�� j�� �ٲ۴�.
		}
	}
	// ������ i�� �ٴٸ��� �� ��, ������ �Ϸ�Ǿ���
	pivp = j; // ���� j�� ��ġ�� pivot�� ��ġ�� �Ǿ�� �ϹǷ� �ٲ�
	// ������ �Ǿ��� ù��° ���� �� ��ġ�� ���� �ٲ�
	//(ũ��� pivot�� �� �ڸ��� ������ pivot�� �� ŭ) 
	Swap(Arr[low], Arr[pivp]);
}

// ������ ���� �� ������ �κ�
void _fastquick(int* Arr, int low, int high)		// ������ ������ ���Լ�
{
	int P_Point = 0;
	
	if (high - low > 20) // �迭 20���� ������ ��, �� ������ ��ġ�� �ʰ� ��
	{
		_fastpatition(Arr, low, high, P_Point);		// �ǹ��� �������� ����
		_fastquick(Arr, low, P_Point - 1);			// �ǹ����� ���� �迭
		_fastquick(Arr, P_Point + 1, high);		// �ǹ����� ū �迭
	}	
	else if (low < high)
	// ����, �迭�� ũ�Ⱑ ����� �۰�, low�� high���� ���� �������� ���¶��
	{
		_insertionS(Arr, low, high);			// ���������� ���� ���ķ� �Ѵ�.
	}
}
void _fastpatition(int* Arr, int low, int high, int& pivp)
{
	int P_Item = 0;		// �ǹ���
	int i = low + 1, j = high;	// �ǹ��� ��ó������ �о�ְ� �������� ��

	// �ǹ��� ���� �������� �����Ѵ�. (�ε����� �������� �����ؼ� ����)
	int R = ((((unsigned int)rand() << 15) | rand()) % (high - low)) + low;
	P_Item = Arr[R];	
	Swap(Arr[low], Arr[R]);		// ������ Pivot�� ���� �� ������ �Ű� �з����� �����Ӱ� ��

	// i�� �ǹ����� ���� ���� �������ϰ�,
	// j�� �ǹ����� ū������ ������ �ȴ�.
	while(1)
	{
		// �ǹ����� ū i�� ã��,
		while (Arr[i] < P_Item)
			++i;
		// �ǹ����� ���� j�� ã�´�.
		while (Arr[j] > P_Item)
			--j;

		// ���� j�� i�� ���� �Ѱ� �۾����� �Ǹ� Ž���� ����
		if (i > j)
			break;

		// ��� ã������ i�� j�� ���� Swapping
		Swap(Arr[i], Arr[j]);
	}
	// j�� �ٷ� �ǹ��� ��ġ�� �ǹǷ�, �ǹ��� j���� �ٲ�
	pivp = j;
	Swap(Arr[j], Arr[low]);
}
void _insertionS(int* Arr, int low, int high)
{
	int i = low + 1, j = 0;			// i�� ó�� ������ low + 1���� ������
	// ������ �迭�� ���� �ּ� 2���� ���ϰ�, �߰��� �����ϱ� ����
	int key = 0;

	while (i < high)			// i�� high�� �� ������
	{
		key = Arr[i];			// key�� i�� ��ġ�� ��. (ó���� low+1)
		for (j = i - 1; j >= 0 && Arr[j] > key; j--)
			Arr[j + 1] = Arr[j];		
			// ����, j�� ���� key���� ũ�ٸ�, key�� ������� ������ ����� ���� ��ĭ �ڷ� �̷�
		// �ݺ��ϴٰ� �ᱹ, j�� �� �ڸ��� ã�Ƴ���, j�� ������ ��ĭ �� ���ư�.
		Arr[j + 1] = key; // ���� j +1 �� ���� ����ְ� ��.
		i++;	//i++ ��.
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
