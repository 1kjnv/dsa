#include <stdio.h>

void merge(int *nums, int left, int middle, int right)
{
	int i, j, k;
	int n1 = middle - left + 1;
	int n2 = right - middle;

	int L[n1], R[n2];
	
	for(i = 0; i < n1; i++)
	{
		L[i] = nums[left + i];
	}

	for(j = 0; j < n2; j++)
	{
		R[j] = nums[middle + 1 + j];
	}

	i = 0;
	j = 0;
	k = left;
	while(i < n1 && j < n2)
	{
		if(L[i] <= R[j])
		{
			nums[k] = L[i];
			i++;
		}
		else
		{
			nums[k] = R[j];
			j++;
		}
		k++;
	}

	while(i < n1)
	{
		nums[k] = L[i];
		i++;
		k++;
	}

	while(j < n2)
	{
		nums[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int* nums, int left, int right)
{
	if(left < right)
	{
		int middle = left + (right - left) / 2;

		mergeSort(nums, left, middle);
		mergeSort(nums, middle + 1, right);

		merge(nums, left, middle, right);
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
	int nums[] = { 12, 11, 13, 5, 6, 7 };
	int size = sizeof(nums) / sizeof(nums[0]);

	printArray(nums, size);
	mergeSort(nums, 0, size-1);
	printArray(nums, size);

	return 0;
}
