#include "sort.h"

/**
 * swap_list - It swaps two nodes of a list
 * @first: The node with a bigger value
 * @second: The node with a smaller value
 * Return: Nothing
 */
void swap_list(listint_t *first, listint_t *second)
{
	listint_t *tmp;

	if (second->next)
		second->next->prev = first;
	if (first->prev)
		first->prev->next = second;
	first->next = second->next;
	second->next = first;

	tmp = first->prev;
	first->prev = second;
	second->prev = tmp;
}



/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 *                       in ascending order using the Insertion sort algorithm
 * @list: The pointer to the list
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *first;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = *list;
	while (current)
	{
		first = current;

		while (first->prev && (first->n < first->prev->n))
		{
			swap_list(first->prev, first);
			if (first->prev == NULL)
				*list = first;
			print_list(*list);
		}
		current = current->next;
	}
}
