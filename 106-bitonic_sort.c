#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/**
 * bitonic_merge - Merges two subarrays of the given array in a bitonic manner
 * @array: The array to be sorted
 * @low: Starting index of the first subarray
 * @count: Number of elements to be sorted in each subarray
 * @ascending: Flag indicating whether the merging is in ascending order
 */
void bitonic_merge(int *array, size_t low, size_t count, bool ascending)
{
	if (count > 1)
	{
		size_t k = count / 2;
		size_t i;

		printf("Merging [%lu/%lu] (%s):\n", count, count, ascending ? "UP" : "DOWN");
		for (i = low; i < low + count; i++)
			printf("%d%s", array[i], (i < low + count - 1) ? ", " : "\n");

		bitonic_merge(array, low, k, true);
		bitonic_merge(array, low + k, k, false);

		for (i = low; i < low + k; i++)
		{
			if ((array[i] > array[i + k]) == ascending)
			{
				int temp = array[i];
				array[i] = array[i + k];
				array[i + k] = temp;
			}
		}

		printf("Result [%lu/%lu] (%s):\n", count, count, ascending ? "UP" : "DOWN");
		for (i = low; i < low + count; i++)
			printf("%d%s", array[i], (i < low + count - 1) ? ", " : "\n");
	}
}

/**
 * bitonic_sort_recursive - Recursively sorts a subarray of the given array
 *                          in a bitonic manner
 * @array: The array to be sorted
 * @low: Starting index of the subarray
 * @count: Number of elements to be sorted
 * @ascending: Flag indicating whether the sorting is in ascending order
 */
void bitonic_sort_recursive(int *array, size_t low, size_t count, bool ascending)
{
	if (count > 1)
	{
		size_t k = count / 2;
		size_t i;

		printf("Splitting [%lu/%lu] (%s):\n", count, count, ascending ? "UP" : "DOWN");
		for (i = low; i < low + count; i++)
			printf("%d%s", array[i], (i < low + count - 1) ? ", " : "\n");

		bitonic_sort_recursive(array, low, k, true);
		bitonic_sort_recursive(array, low + k, k, false);
		bitonic_merge(array, low, count, ascending);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using
 *                the Bitonic sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2 || (size & (size - 1)) != 0)
		return;

	bitonic_sort_recursive(array, 0, size, true);
}
