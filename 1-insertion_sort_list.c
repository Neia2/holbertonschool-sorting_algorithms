#include "sort.h"

/**
 * insertion_sort_list -  sorts a DLL of integers using the Insertion sort
 * @list: DLL to sort
 * Return: Nothing.
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *tmp_node, *aux_node;

    tmp_node = (*list)->next;
    while (tmp_node != NULL)
    {
        aux_node = tmp_node;
        tmp_node = tmp_node->next;

        while (aux_node->prev != NULL && aux_node->n < aux_node->prev->n)
        {
            aux_node->prev->next = aux_node->next;

            if (aux_node->next != NULL)
                aux_node->next->prev = aux_node->prev;

            aux_node->next = aux_node->prev;
            aux_node->prev = aux_node->prev->prev;

            if (aux_node->prev == NULL)
                *list = aux_node;
            else
                aux_node->prev->next = aux_node;

            aux_node->next->prev = aux_node;

            print_list(*list);
        }
    }
}
