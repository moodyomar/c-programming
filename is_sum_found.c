#include <stdio.h>

int isSumFound(int *ar, int size, int sum);

int main()
{
	int array[] = {2, 4, 7, 12, 14};
	isSumFound(array,5,21);

	return 0;
}


int isSumFound(int *ar, int size, int sum)
{

	int left = 0, right = size - 1;
	while(left < right)
	{
		if(ar[left] + ar[right] == sum)
		{
			return	printf("the indexes are: %d %d \n",left,right);
		}
		else if(ar[left] + ar[right] > sum)
		{
			right--;
		}
		else
		{
			left++;
		}
	}
	return 0;
}
