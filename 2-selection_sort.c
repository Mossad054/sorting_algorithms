#include "sort.h"

/**
 * swap_intgrs - swap two integers in an array.
 * @i:  first integer to swap.
 * @j: second integer to swap.
 */
void swap_intgrs(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

/**
 * selection_sort - Sorts array of int in ascending order
 *                  using  selection sort algorithm.
 * @array: array of integers
 * @size: size of the array
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap_intgrs(array + i, min);
			print_array(array, size);
		}
	}
}
