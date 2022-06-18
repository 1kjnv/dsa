#include <stdio.h>

int search(int arr[], int size, int target);

int main(void)
{
	int arr[] = { 2,3,4,10,40, 23, 543, 13, 6 };
	int size = sizeof(arr) / sizeof(arr[0]);

	int target = 23;

	int result = search(arr, size, target);

	(result == -1)
		? printf("Item does NOT exist")
		: printf("Item index: %d\n", result);

	return 0;
}

int search(int arr[], int size, int target)
{
	int i;
	for(i = 0; i < size; ++i)
	{
		if(arr[i] == target)
		{
			return i;
		}
	}
	return -1;
}
