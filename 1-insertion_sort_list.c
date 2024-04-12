#include "sort.h"

/**
 * insertion_sort_list - Sorts a list of integers in ascending order
 *                        using the Insertion sort algorithm
 * @list: Double pointer to the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr = (*list)->next;
	listint_t *prev = curr->prev;
	listint_t *temp = curr->next;

		if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

<<<<<<< HEAD
=======
		listint_t *curr = (*list)->next;
		listint_t *prev, *temp;

>>>>>>> 66f9c43 (quick sort)
	while (curr != NULL)
	{
		while (prev != NULL && prev->n > curr->n)
		{
			if (prev->prev != NULL)
			prev->prev->next = curr;
			if (curr->next != NULL)
			curr->next->prev = prev;

			curr->prev = prev->prev;
			prev->next = curr->next;
			curr->next = prev;
			prev->prev = curr;

			if (curr->prev == NULL)
				*list = curr;

			print_list(*list);

			prev = curr->prev;
		}

			curr = temp;
		}
}
