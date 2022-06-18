#include <stdio.h>

void swap(int *a, int *b);
void selection_sort(int arr[], int size);
void print_array(int arr[], int size);

int main(void)
{
	int arr[] = { 64, 25, 12, 22, 11 };
	int size = sizeof(arr) / sizeof(arr[0]);

	printf("Before sorting: ");
	print_array(arr, size);

	selection_sort(arr, size);

	printf("After sorting: ");
	print_array(arr, size);

	return 0;
}

void selection_sort(int arr[], int size)
{
	int i, j, min;
	for(i = 0; i < size-1; i++)
	{
		min = i;
		for(j = i+1; j < size; j++)
		{
			if(arr[min] > arr[j])
			{
				min = j;
			}
		}
		swap(&arr[min], &arr[i]);
	}
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
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
