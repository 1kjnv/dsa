#include <stdio.h>

void swap(int *a, int *b);
void heapify(int arr[], int size, int i);
void build_heap(int arr[], int size);
void print_heap(int arr[], int size);

int main(void)
{
	int arr[] = { 1,3,5,4,6,13,10,9,8,15,17 };
	int size = sizeof(arr) / sizeof(arr[0]);

	printf("Before: ");
	print_heap(arr, size);

	build_heap(arr, size);
	printf("After: ");
	print_heap(arr, size);

	return 0;
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
};

// time complexity is O(log n)
void heapify(int arr[], int size, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if(left < size && arr[left] > arr[largest])
	{
		largest = left;
	}
	if(right < size && arr[right] > arr[largest])
	{
		largest = right;
	}
	if(largest != i)
	{
		swap(&arr[i], &arr[largest]);
		heapify(arr, size, largest);
	}
}

// time complexity is O(n log n)
void build_heap(int arr[], int size)
{
	for(int i = (size / 2) - 1; i >= 0; --i)
	{
		heapify(arr, size, i);
	}
}

void print_heap(int arr[], int size)
{
	for(int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

