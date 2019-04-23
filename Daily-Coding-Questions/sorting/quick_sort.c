#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) // used to part the function and return the index at which left part is 
	//less then the index and right part is greater than the index.
{
    int i = low;
    int pivot = arr[high];

    for(int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
		swap(&arr[i], &arr[j]);
		i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return (i);
}

void quick_sort(int arr[], int low, int high)
{
	if(low < high)
	{
		int partition_index = partition (arr, low, high);
		quick_sort(arr, low, partition_index - 1); // recursively call the left part of the partition_index
		quick_sort(arr, partition_index + 1, high); // recursively call the right part of the partition_index
	}
}

void print_arr(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main(void)
{
    int arr[] = {9, 6, 10, 8, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    quick_sort(arr, 0, size - 1);
    print_arr(arr, size);
    return 0;
}
