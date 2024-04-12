#include "sort.h"

void quicksort(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high, size_t size);

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort(array, 0, size - 1, size);
}

/**
 * quicksort - Recursive function to perform quick sort
 * @array: Array to be sorted
 * @low: Starting index of the array
 * @high: Ending index of the array
 * @size: Size of the array
 */
void quicksort(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pi;
        pi = partition(array, low, high, size);

        quicksort(array, low, pi - 1, size);
        quicksort(array, pi + 1, high, size);
    }
}

/**
 * partition - Partitioning scheme to select the pivot
 * @array: Array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 *
 * Return: Index of the pivot element
 */
int partition(int *array, int low, int high, size_t size)
{
    int pivot = array[low];
    int i = low - 1;
    int j = high + 1;
    int temp;

    while (1)
    {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        print_array(array, size);
    }
}