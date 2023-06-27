#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in ascending order using
 *                 the Counting sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count = NULL, *output = NULL;
	int max_value = 0;
	size_t i;

	/* Find the maximum value in the array */
	for (i = 0; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	/* Allocate memory for count array */
	count = malloc((max_value + 1) * sizeof(int));
	if (count == NULL)
		return;

	/* Initialize count array with zeros */
	for (i = 0; i <= (size_t)max_value; i++)
		count[i] = 0;

	/* Count the occurrences of each element in the array */
	for (i = 0; i < size; i++)
		count[array[i]]++;

	/* Print the count array */
	print_array(count, max_value + 1);

	/* Modify the count array to contain the actual positions of elements */
	for (i = 1; i <= (size_t)max_value; i++)
		count[i] += count[i - 1];

	/* Allocate memory for the output array */
	output = malloc(size * sizeof(int));
	if (output == NULL)
	{
		free(count);
		return;
	}

	/* Build the output array */
	for (i = 0; i < size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	/* Copy the sorted elements back to the original array */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	/* Free the allocated memory */
	free(count);
	free(output);
}
