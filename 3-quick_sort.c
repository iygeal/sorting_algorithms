#include "sort.h"

/**
 * hoare_partition - Hoare partition scheme for Quick sort
 * @array: The array to be partitioned
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 * @size: Number of elements in the array
 * Return: Returns the pivot index
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot, temp;
	int i = low - 1;
	int j = high + 1;

	/* Choose the middle element as the pivot */
	pivot = array[low + (high - low) / 2];

	while (1)
	{
		/* Find element on the left to swap */
		do {
			i++;
		} while (array[i] < pivot);

		/* Find element on the right to swap */
		do {
			j--;
		} while (array[j] > pivot);

		/* If pointers meet, the partition is complete */
		if (i >= j)
			return (j);

		/* Swap elements at i and j */
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;

		/* Print the array after each swap for visualization */
		print_array(array, size);
	}
}

/**
 * hoare_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @low: The starting index of the array partition to order.
 * @high: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int low, int high)
{
	int pivot;

	if (low < high)
	{
		/* Partition the array and get the pivot index */
		pivot = hoare_partition(array, low, high, size);

		/* Recursively sort the sub-arrays */
		hoare_sort(array, size, low, pivot);
		hoare_sort(array, size, pivot + 1, high);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	/* Call the recursive hoare_sort function */
	hoare_sort(array, size, 0, size - 1);
}
