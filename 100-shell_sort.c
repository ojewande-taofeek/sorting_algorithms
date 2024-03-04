#include "sort.h"


/**
 * shell_sort - Sorts an array using Knuth sequence
 * @array: An array to be sorted
 * @size: Size of the array
 * Return: Nothing
 */

void shell_sort(int *array, size_t size)
{
	int interval, idx, j;
	int tmp;

	if (!array || size <= 0)
		return;

	interval = 1;
	while (interval < (int)(size / 3))
		interval = (interval * 3) + 1;  /* Knuth sequence */
	while (interval > 0)
	{
		for (idx = interval; idx < (int)(size); idx++)
		{
			tmp = array[idx];
			j = idx;
			while (j >= interval && (array[j - interval] > tmp))
			{
				array[j] = array[j - interval];
				j -= interval;
			}
			array[j] = tmp;
		}
		interval /= 3;
		print_array(array, size);
	}
}
