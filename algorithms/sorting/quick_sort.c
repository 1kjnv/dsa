#include <stdio.h>

void swap(int* a, int* b);
int partition(int* nums, int left, int right);
void quick_sort(int* nums, int left, int right);
void print_array(int* nums, int arr_size);

int main()
{
	int nums[] = { 10, 7, 43, 8, 1, 6 };
	int size = sizeof(nums) / sizeof(nums[0]);

	printf("Before: ");
	print_array(nums, size);

	quick_sort(nums, 0, size-1);

	printf("After: ");
	print_array(nums, size);

	return 0;
}

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

		quick_sort(nums, left, pivot - 1);
		quick_sort(nums, pivot + 1, right);
	}
}

void print_array(int* nums, int arr_size)
{
	for(int i = 0; i < arr_size; i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");
}

