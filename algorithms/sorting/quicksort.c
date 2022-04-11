#include <stdio.h>

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int* nums, int left, int right)
{
	int pivot = nums[right];
	int i = left - 1;

	for(int j = left; j < right; j++)
	{
		if(nums[j] <= pivot)
		{
			i++;
			swap(&nums[i], &nums[j]);
		}
	}
	swap(&nums[i+1], &nums[right]);
	return (i + 1);
}

void quicksort(int* nums, int left, int right)
{
	if(left < right)
	{
		int pivot = partition(nums, left, right);

		quicksort(nums, left, pivot - 1);
		quicksort(nums, pivot + 1, right);
	}
}

void printArray(int* nums, int arrSize)
{
	for(int i = 0; i < arrSize; i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");
}

int main()
{
	int nums[] = { 10, 7, 43, 8, 1, 6 };
	int size = sizeof(nums) / sizeof(nums[0]);

	printArray(nums, size);
	quicksort(nums, 0, size-1);
	printArray(nums, size);

	return 0;
}
