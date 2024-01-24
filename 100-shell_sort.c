#include "sort.h"
/**
 * shell_sort - Sorts an array of integers in ascending order
 *              using the Shell sort algorithm with Knuth sequence
 * @array: The array to be sorted
 * @size: Number of elements (integers) in the array
*/
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	/* Check for empty or single-element array */
	if (array == NULL || size < 2)
		return;

	/* Calculate the initial gap using Knuth sequence */
	while (gap < size / 3)
	{
		gap = gap * 3 + 1;
	}
	while (gap > 0)
	{
		/* Perform insertion sort with current gap */
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			/* Shift elements until correct position for temp is found*/
			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			/* Place temp at its correct position */
			array[j] = temp;
		}
		/* Reduce the gap according to Knuth sequence */
		gap = (gap - 1) / 3;

		/* Print array after each gap reduction for visualization */
		print_array(array, size);
	}
}
