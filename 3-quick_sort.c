#include "sort.h"


/**
 * swap_Array - Swap two elements in an array
 *
 * @array: Pointer that point to an array
 * @j: This is the index to swap with the index k
 * @k: This is the index to swap with the index j
 *
 */

void swap_Array(int *array, size_t j, size_t k)
{
	int temp;

	temp = array[j];
	array[j] = array[k];
	array[k] = temp;
}

/**
 * quick_sort - Algorithm for Quick Sort
 *
 * @array: Pointer that points to an array
 * @size: The size of the array
 *
 */
void quick_sort(int *array, size_t size)
{
	modifyQuickSort(array, 0, size - 1, size);
}

/**
 * lomuto_partition - Function that implements the Lomuto Partition Scheme
 *
 * @arr: Pointer that points to an array
 * @low: The minimum index
 * @high: The maximum index
 * @size: The size of the array
 *
 * Return: The number of the partition
 */

int lomuto_partition(int *arr, int low, int high, int size)
{
	int pivot = arr[high];
	int j, i = (low  - 1);

	for (j = low; j <= high; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap_Array(arr, i, j);
				print_array(arr, size);
			}
		}
	}
	return (i);
}

/**
 * modifyQuickSort - Recursive function to modify Quick Sort
 *
 * @arr: Pointer that points to an array
 * @low: The minimum index
 * @high: The maximum index
 * @size: The size of the array
 *
 */
void modifyQuickSort(int *arr, int low, int high, int size)
{
	if (low < high)
	{
		int pi = lomuto_partition(arr, low, high, size);

		/* Recursively sort the sub-arrays */

		/* Sort the left subarray (elements less than the pivot).*/
		modifyQuickSort(arr, low, pi - 1, size);

		/* Sort the right subarray (elements greater than the pivot).*/
		modifyQuickSort(arr, pi + 1, high, size);
	}
}
