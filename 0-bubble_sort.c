#include "sort.h"
/**
 * bubble_sort - function that sorts an array of integers in
 *               ascending order using the Bubble sort algorithm
 * @array: An array of number to be sorted
 * @size: Size of the array
 * Return: Nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	size_t checker, temp;

	for (i = 0; i < size - 1; i++)
	{
		checker = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				checker = 1;
				print_array(array, size);
			}
		}
		if (checker == 0)
			break;
	}
}
