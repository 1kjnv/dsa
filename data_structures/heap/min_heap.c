#include <stdio.h>

void swap(int *a, int *b);
void heapify(int arr[], int size, int i);
void build_heap(int arr[], int size);
void print_heap(int arr[], int size);

int main(void)
{
	int arr[] = { 20, 19, 17, 10, 18, 4, 14, 8, 3, 12 };
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
	int smallest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if(left < size && arr[left] < arr[smallest])
	{
		smallest = left;
	}
	if(right < size && arr[right] < arr[smallest])
	{
		smallest = right;
	}
	if(smallest != i)
	{
		swap(&arr[i], &arr[smallest]);
		heapify(arr, size, smallest);
	}
}

// time complexity is O(n log n)
void build_heap(int arr[], int size)
{
	for(int i = size/2-1; i >= 0; --i)
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

