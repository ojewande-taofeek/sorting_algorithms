#include "sort.h"
/**
 * swap - The function swaps two elements in an array
 * @first: The first element
 * @second: The second element
 * Return: Nothing
 */

void swap(int *first, int *second)
{
	int temp = *first;

	*first = *second;
	*second = temp;
}


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
	size_t checker;

	if (array && size > 0)
	{
		for (i = 0; i < size - 1; i++)
		{
			checker = 0;
			for (j = 0; j < size - i - 1; j++)
			{
				if (array[j] > array[j + 1])
				{
					swap(&array[j], &array[j + 1]);
					checker = 1;
					print_array(array, size);
				}
			}
			if (checker == 0)
				break;
		}
	}
}
