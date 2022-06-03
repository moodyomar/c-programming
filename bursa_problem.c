#include <stdio.h>

int BestPrice();

int main()
{
	int prices[] = {6, 12, 3, 5, 1, 4, 9, 2};
	int arr_len = (sizeof(prices) / sizeof(prices[0]));

	printf("Profit: %d \n ",BestPrice(prices, arr_len));

	return 0;
}


int BestPrice(int *arr, int size)
{
	int profit = 0;
	int current_min = arr[0];
	int min = arr[0],  max = arr[0];

	for (int i = 0; i < size; i++)
	{
		if (arr[i] < current_min)
		{
			current_min = arr[i];
		}
		
		if ((arr[i] - current_min) > profit)
		{
			profit = arr[i] - current_min;
			max = arr[i];
		}
		
	}
	return profit;
}

