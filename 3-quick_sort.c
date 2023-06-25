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
		int pivot = lomuto_partition(array, low, high, high - low + 1);

		quicksort_recursive(array, low, pivot - 1);
		quicksort_recursive(array, pivot + 1, high);
	}
}


/**
 * lomuto_partition - Lomuto partition scheme
 * @array: The array to be sorted
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 * @size: Size of the array
 *
 * Return: Index of the pivot element
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}

	if (array[high] < array[i + 1])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}


/**
 * swap - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
