#include <stdio.h>

void insertion_sort(int arr[], int size);
void print_array(int arr[], int size);

int main(void)
{
	int arr[] = { 12, 11, 13, 5, 6 };
	int size = sizeof(arr) / sizeof(arr[0]);

	printf("Before sorting: ");
	print_array(arr, size);

	insertion_sort(arr, size);

	printf("After sorting: ");
	print_array(arr, size);

	return 0;
}

void insertion_sort(int arr[], int size)
{
	int i, j, key;
	for(i = 1; i < size; ++i)
	{
		key = arr[i];
		j = i - 1;
		while(j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void print_array(int arr[], int size)
{
	int i;
	for(i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
