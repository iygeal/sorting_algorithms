#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 * @list: Pointer to the pointer to the doubly linked list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *previousNode;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	/*Start sorting from the second node in the list*/
	current = (*list)->next;

	while (current != NULL)
	{
		/*Save the current node to be inserted*/
		temp = current;
		/*Move to the next node in the list*/
		current = current->next;

		/*Move the current node to its correct sorted position*/
		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			previousNode = temp->prev;

			/*Adjust pointers to perform the swap*/
			if (temp->next != NULL)
				temp->next->prev = previousNode;
			previousNode->next = temp->next;
			temp->next = previousNode;
			temp->prev = previousNode->prev;
			previousNode->prev = temp;

			/*If the current node becomes the new head of the list*/
			if (temp->prev != NULL)
				temp->prev->next = temp;
			else
				*list = temp;

		/*Print the list after each swap for visualization*/
		print_list(*list);
		}
	}
}
