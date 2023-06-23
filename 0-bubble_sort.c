#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 *	using the Bubble sort algorithm.
 * @array: array to be sorted.
 * @size: the size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t j, i;
	int temp, swap;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swap = 0;/*track the inner loop for a swap*/

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				/* swapping element of array */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swap = 1;
				print_array(array, size);
			}
		}

		/* printing array after each swap */
		for (j = 0; j < size; j++)
		{
			printf("%d ", array[j]);
		}

		printf("\n");

		/* condition on a no swap occuring */
		if (swap == 0)
			break;
	}
}
