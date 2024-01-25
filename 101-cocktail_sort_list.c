#include "sort.h"
/**
 * cocktail_sort_list - Sorts a doubly linked list in ascending order
 *                      using the Cocktail Shaker sort algorithm
 * @list: Pointer to a pointer to the doubly linked list
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int swapped = 1;

	if (list == NULL || *list == NULL)
		return;

	while (swapped)
	{
		swapped = 0;
		/* Traverse forward and swap elements as needed */
		for (current = *list; current->next != NULL; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				swapped = 1;  /* Swapped = 1 if swap occurs */
				print_list(*list);
			}
		}
		if (!swapped)
			break;

		swapped = 0;  /* Reset to 0 before backward traversal */
		/* Traverse backward and swap elements as neeeded */
		for (current = current->prev; current != NULL; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				swapped = 1;
				print_list(*list);
			}
		}
	}
	free_list(*list);
	*list = NULL;
}
/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to a pointer to the doubly linked list
 * @node1: First node to swap
 * @node2: Second node to swap
*/
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *temp;

	if (node1 == NULL || node2 == NULL)
		return;

	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next != NULL)
		node2->next->prev = node1;

    /* Swap the prev pointers */
	temp = node1->prev;
	node1->prev = node2->prev;
	node2->prev = temp;

    /* Swap the next pointers */
	temp = node1->next;
	node1->next = node2->next;
	node2->next = temp;
}
/**
 * free_list - Frees the memory allocated for a doubly linked list
 * @list: Pointer to the head of the doubly linked list
*/
void free_list(listint_t *list)
{
	listint_t *current = list;
	listint_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
