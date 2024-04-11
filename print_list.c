#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
    const listint_t *temp = list;

    while (temp != NULL)
    {
        printf("%d", temp->n);
        if (temp->next != NULL)
            printf(", ");
        temp = temp->next;
    }
    printf("\n");
}