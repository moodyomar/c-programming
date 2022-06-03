#include <stdio.h>

void ShowArr(int arr[], size_t size);

	int main()
{

	int arr[] = {1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0};
	size_t arr_s = sizeof(arr) / sizeof(arr[0]);
	int ones = 0, zeros = 0;
	int sorted_arr[arr_s];

	ShowArr(arr, arr_s);

	for (int i = 0; i < arr_s; i++)
	{
		if (arr[i])
		{
			ones++;
		}
		else
		{
			zeros++;
		}
	}


	for (int i = 0; i < arr_s; i++)
	{
		if (!zeros)
		{
			sorted_arr[i] = 1;
		}
		else
		{
			sorted_arr[i] = 0;
			zeros--;
		}
	}

	ShowArr(sorted_arr, arr_s);

	return 0;
}

void ShowArr(int arr[], size_t size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d", arr[i]);
	}
	puts("\n");
}
