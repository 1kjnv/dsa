#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return (*(int*)a - *(int*)b);
}

int binarySearch(int* nums, int left, int right, int val)
{
	// first we sort the given array
	// because binary search only works
	// on sorted arrays
	qsort(nums, right+1, sizeof(int), cmp);

	// then we recursively search the value
	// and return its index if found 
	// or -1 if NOT found.
	int middle;
	while(left < right)
	{
		middle = left + (right - left) / 2;
		if(nums[middle] == val)
		{
			return middle;
		}
		if(nums[middle] < val)
		{
			return binarySearch(nums, middle + 1, right, val);
		}
		return binarySearch(nums, left, middle - 1, val);
	}
	return -1;
}

int main()
{
	int nums[] = { 32, 4, 13, 6, 3 };
	int size = sizeof(nums) / sizeof(nums[0]);

	printf("Result: %d\n", binarySearch(nums, 0, size-1, 13));

	return 0;
}
