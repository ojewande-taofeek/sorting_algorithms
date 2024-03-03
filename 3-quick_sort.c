#include "sort.h"

/**
 * swap_array - Swaps two elements of an array
 * @array: The unsorted/sorted array
 * @first: The first element to swap
 * @second: The second element to swap
 * Return: Nothing
 */

void swap_array(int *array, int first, int second)
{
	int tmp = array[first];

	array[first] = array[second];
	array[second] = tmp;
}

/**
 * partition - Its partitions the array into two
 * @array: The unsorted/sorted array
 * @low: The least index of the array usually 0
 * @high: The size of the array - 1
 * @size: The size of the array
 * Return: Right position of index found
 */

int partition(int *array, int low, int high, size_t size)
{
	int idx, j;
	int pivot = array[high];

	idx = (low - 1);

	for (j = low; j <= high; j++)
	{
		if (array[j] < pivot)
		{
			idx++;
			if (j != idx)
			{
				swap_array(array, idx, j);
				print_array(array, size);
			}
		}
	}
	if (idx + 1 != high)
	{
		swap_array(array, idx + 1, high);
		print_array(array, size);
	}
	return (idx + 1);

}

/**
 * sorter - Recursively sort the array
 * @array: The unsorted/sorted array
 * @low: The least index of the array usually 0
 * @high: The size of the array - 1
 * @size: The size of the array
 * Return: Nothing
 */

void sorter(int *array, int low, int high, size_t size)
{
	int pat;

	if (low < high)
	{
		pat = partition(array, low, high, size);
		sorter(array, low, pat - 1, size);
		sorter(array, pat + 1, high, size);
	}
}

/**
 * quick_sort - Uses partitioning to sort an array
 * @array: The unsorted/sorted array
 * @size: Size of the array
 */

void quick_sort(int *array, size_t size)
{
	int low, high;

	if (!array || size < 2)
		return;

	if (array && size > 1)
	{
		low = 0;
		high = size - 1;
		sorter(array, low, high, size);
	}
}
