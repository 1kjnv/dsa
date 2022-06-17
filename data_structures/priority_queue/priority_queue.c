#include <stdio.h>

int size = 0;

void swap(int *a, int *b);
void heapify(int arr[], int size, int i);
void insert(int arr[], int val);
void delete(int arr[], int val);
void print_array(int arr[], int size);

int main(void)
{
	int arr[10];

	insert(arr, 2);
	insert(arr, 4);
	insert(arr, 5);
	insert(arr, 7);
	insert(arr, 8);
	insert(arr, 12);
	
	printf("Priority queue: ");
	print_array(arr, size);

	return 0;
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

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

void insert(int arr[], int val)
{
	if(size == 0)
	{
		arr[0] = val;
		size++;
	}
	else
	{
		arr[size] = val;
		++size;
		for(int i = size / 2 - 1; i >= 0; i--)
		{
			heapify(arr, size, i);
		}
	}
}

void delete(int arr[], int num)
{
	int i;
	for(i = 0; i < size; i++)
	{
		if(num == arr[i])
		{
			break;
		}
	}

	swap(&arr[i], &arr[size-1]);
	--size;
	for(i = size / 2 - 1; i >= 0; i--)
	{
		heapify(arr, size, i);
	}
}

void print_array(int arr[], int size)
{
	for(int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

