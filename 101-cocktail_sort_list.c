#include "sort.h"

/**
 * swap_front_dl - Swaps two nodes during forward sorting
 * @current: The current node
 * @temp: The next of the current node
 * Return: Nothing
 */
void swap_front_dl(listint_t *current, listint_t *temp)
{
	if (current->prev)
		current->prev->next = temp;
	if (temp->next)
		temp->next->prev = current;

	current->next = temp->next;
	temp->prev = current->prev;
	current->prev = temp;
	temp->next = current;
}

/**
 * swap_back_dl - Swaps two nodes during backward sorting
 * @current_back: The current node during backwad sorting
 * @temp_back: The prev of the current_back node
 * Return: Nothing
 */

void swap_back_dl(listint_t *current_back, listint_t *temp_back)
{
	if (current_back->next)
		current_back->next->prev = temp_back;
	if (temp_back->prev)
		temp_back->prev->next = current_back;
	current_back->prev = temp_back->prev;
	temp_back->next = current_back->next;
	current_back->next = temp_back;
	temp_back->prev = current_back;
}

/**
 * forward - It sorts the list forward using bubblesort
 * @list: The list of nodes
 * @high: The highest value
 * @low: The lowest value
 * @swapped: CHanges to 1, if two nodes are swapped
 * @done: Changes to 0, if swapped occurs and maintains the current
 * Return: high
 */
listint_t  *forward(listint_t **list, listint_t *high, listint_t *low,
		int *swapped, int done)
{
	listint_t *current, *temp;

	current = *list;
	if (low)
		current = low->next;
	while (current->next != high)
	{
		done = 1; /* if a node is swapped, current unchanged */
		if (current->n > current->next->n)
		{
			temp = current->next;
			swap_front_dl(current, temp);
			*swapped = 1;
			done = 0;
			print_list(*list);
		}
		if (done) /*if no swaps, move current to the next node */
			current = current->next;
	}
	high = current;
	return (high);
}
/**
 * cocktail_sort_list - function that sorts a doubly linked list of integers
 *                     in ascending order using the Cocktail shaker sort
 *                     algorithm
 * @list: The head pointer to the list
 * Return: Nothing
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *high, *current_back, *low, *temp_back;
	int done, swapped = 0;

	if (!list || *list == NULL || (*list)->next == NULL)
		return;
	high = NULL;
	low = NULL;

	while (1)
	{
		swapped = 0; /* to check if two nodes are swapped */
		high = forward(list, high, low, &swapped, done);
		if (!swapped)
			break;
		if (high->prev)
		{
			swapped = 0;
			current_back = high->prev;
			while (current_back->prev != low)
			{
				done = 1;
				if (current_back->n < current_back->prev->n)
				{
					temp_back = current_back->prev;
					swap_back_dl(current_back, temp_back);
					swapped = 1;
					done = 0;
					if (current_back->prev == NULL)
						*list = current_back;
					print_list(*list);
				}
				if (done)
					current_back = current_back->prev;
			}
			low = current_back;
		}

	}
}
