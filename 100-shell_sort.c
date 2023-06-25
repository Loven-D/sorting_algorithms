#include "sort.h"
#include <stdio.h>

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t i, j;
	int temp;

	/* Calculate the initial gap using the Knuth sequence */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap >= 1)
	{
		/* Perform insertion sort for each gap */
		for (i = gap; i < size; i++)
		{
			/* Insert array[i] into the sorted sequence array[0...i-gap] */
			temp = array[i];
			j = i;
			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}

		print_array(array, size);
		gap /= 3; /* Decrease the gap */
	}
}
