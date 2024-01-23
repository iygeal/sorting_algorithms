#include "sort.h"

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort
 * @array: The array to be partitioned
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 * @size: Number of elements in the array
 * Return: Returns the pivot index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, temp;
	int i, j;

    /* Choose the last element as the pivot */
	pivot = array[high];
	i = low - 1;

    /* Iterate through the array and rearrange elements */
	for (j = low; j < high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			/* Swap array[i] and array[j] */
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				/* Print the array after each swap for visualization */
				print_array(array, size);
			}
		}
	}

    /* Swap array[i + 1] and pivot to place pivot in correct position */
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;

    /* Print the array after each swap for visualization */
	print_array(array, size);

    /* Return the pivot index */
	return (i + 1);
}

/**
 * quick_sort_helper - Helper function for recursive Quick sort
 * @array: The array to be sorted
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 * @size: Number of elements in the array
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		/* Partition the array and get the pivot index */
		pivot = lomuto_partition(array, low, high, size);

		/* Recursively sort the sub-arrays */
		quick_sort_helper(array, low, pivot - 1, size);
		quick_sort_helper(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending
 * order using Quick sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

    /* Call the recursive quick_sort_helper function */
		quick_sort_helper(array, 0, size - 1, size);
}
