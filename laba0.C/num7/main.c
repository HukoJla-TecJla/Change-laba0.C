#include <stdio.h>
#include <stdlib.h>
#define R 7
#include <time.h>
int main()
{
	int max_arr;
	int index_max_arr;
	int min_arr;
	int index_min_arr;
	int arr[5];
	srand((unsigned)time(NULL));
	//��������� ������ ���������� ������� � �� ���� ���������� ���� ����. ����� � ���. ����� �������
	for (int i = 0; i < 5; i++)
	{
		arr[i] = rand() % 101;
		printf("%d""\n""\n", arr[i]);// ������� ����������� ������
		if (i == 0)
		{
			max_arr = arr[i];
			index_max_arr = i;
			min_arr = arr[i];
			index_min_arr = i;
		}
		if (arr[i] > max_arr)
		{
			max_arr = arr[i];
			index_max_arr = i;
		}
		else if (arr[i] < min_arr)
		{
			min_arr = arr[i];
			index_min_arr = i;
		}
	}
	// ������ ����. ����� � ���. � �������
	arr[index_max_arr] = min_arr;
	arr[index_min_arr] = max_arr;
	// ������� ������������ ������
	for (int d = 0; d < 5; d++)
	{
		printf("%d""\t", arr[d]);
	}
}