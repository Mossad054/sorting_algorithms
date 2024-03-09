#include "sort.h"

/**
 * swap_intgrs - swaps two integers in an array.
 * @i: first integer to swap.
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
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: array of the integers to sort.
 * @size:  size of array.
 *
 * Description: Prints  array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_intgrs(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
