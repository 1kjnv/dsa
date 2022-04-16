#include <stdio.h>

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
};

void print_array(int arr[], int n)
{
	for(int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void heapify(int arr[], int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if(left < n && arr[left] > arr[largest])
	{
		largest = left;
	}
	if(right < n && arr[right] > arr[largest])
	{
		largest = right;
	}
	if(largest != i)
	{
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}
}

void build_heap(int arr[], int n)
{
	int lastNoneLeafNode = (n / 2) - 1;
	for(int i = lastNoneLeafNode; i >= 0; i--)
	{
		heapify(arr, n, i);
	}
}

int main(void)
{
	int arr[] = { 4, 18, 17, 10, 19, 20, 14, 8, 3, 12 };
	int n = sizeof(arr) / sizeof(arr[0]);

	print_array(arr, n);
	build_heap(arr, n);
	print_array(arr, n);

	return 0;
}
