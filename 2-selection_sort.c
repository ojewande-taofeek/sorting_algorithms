#include "sort.h"

/**
 * swap_array - Function to swap to two array elements
 * @array: The unsorted/sorted array
 * @arr_min: First element to swap, usually it's the lowest
 * @idx: The index of the array checked
 * Return: Nothing
 */

void swap_array(int *array, size_t arr_min, size_t idx)
{
	int tmp;

	tmp = array[arr_min];
	array[arr_min] = array[idx];
	array[idx] = tmp;
}


/**
 * selection_sort - Comaparison sorting algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 * Return: Nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t idx, j, arr_min;

	if (!array || size == 0)
		return;

	for (idx = 0; idx < size - 1; idx++)
	{
		arr_min = idx;
		for (j = idx + 1; j < size; j++)
		{
			if (array[j] < array[arr_min])
				arr_min = j;
		}
		if (arr_min != idx)
		{
			swap_array(array, arr_min, idx);
			print_array(array, size);
		}
	}
}
