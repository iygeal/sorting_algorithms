#include "sort.h"
/**
 * selection_sort - Sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: Number of elements in the array
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		/*Assume current index is index of smallest element*/
		min_idx = i;

		/*Find the index of the min element in the unsorted subarray*/
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			/*Update the min_idx is a smaller element is found*/
				min_idx = j;
		}
		if (min_idx != i)
		{
			/*Swap found min element with first element of unsorted subarray*/
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;

		/*Print the array after each swap for visualization*/
		print_array(array, size);
		}
	}
}
