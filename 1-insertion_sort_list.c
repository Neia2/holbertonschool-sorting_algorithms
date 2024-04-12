#include "sort.h"

/**
 * insertion_sort_list - Sorts a list of integers in ascending order
 *                        using the Insertion sort algorithm
 * @list: Double pointer to the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *sorted = NULL; // Initialize sorted linked list

    listint_t *curr = *list; // Traverse the original list
    while (curr != NULL)
    {
        listint_t *next = curr->next; // Store the next node

        if (sorted == NULL || sorted->n >= curr->n)
        {
            // Insert at the beginning of the sorted list
            curr->next = sorted;
            if (sorted != NULL)
                sorted->prev = curr;
            sorted = curr;
            sorted->prev = NULL;
        }
        else
        {
            // Traverse the sorted list to find the correct position
            listint_t *temp = sorted;
            while (temp->next != NULL && temp->next->n < curr->n)
                temp = temp->next;

            // Insert after temp
            curr->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = curr;
            temp->next = curr;
            curr->prev = temp;
        }

        curr = next; // Move to the next node in the original list
    }

    *list = sorted; // Update the head of the list
}
