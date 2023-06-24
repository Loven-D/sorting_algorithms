#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using Quick sort algorithm (Lomuto partition scheme)
 * @array: Pointer to the array
 * @size: Size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, 0, size - 1);
}

/**
 * quicksort_recursive - Recursive function to perform Quick sort
 * @array: Pointer to the array
 * @low: Lowest index of the partition
 * @high: Highest index of the partition
 */
void quicksort_recursive(int *array, int low, int high)
{
	if (low < high)
	{
		int pivot = lomuto_partition(array, low, high);

		quicksort_recursive(array, low, pivot - 1);
		quicksort_recursive(array, pivot + 1, high);
	}
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort
 * @array: Pointer to the array
 * @low: Lowest index of the partition
 * @high: Highest index of the partition
 *
 * Return: Index of the pivot element
 */
int lomuto_partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j, temp;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, high + 1);
			}
		}
	}

	if (i + 1 != high)
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, high + 1);
	}

	return (i + 1);
}
