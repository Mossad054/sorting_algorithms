#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first int to swap.
 * @b: The second int to swap.
 */

void swap_ints(int *a, int *b)
{
	int tm;

	tm = *a;
	*a = *b;
	*b = tm;
}
/**
 * bubble_sort - Sort an array of int in ascending order.
 * @array: An array of int to sort.
 * @size: The size of the array.
 *
 * Description: Print array after each swap.
 */

/*
Time Complexity: O(n^2)
*/
void bubble_sort(int *array, size_t size)
{
	size_t j, lenn = size;
	bool bubble = false;

	if (array == NULL || size < 2)
		return;

	while (bubble == false)
	{
		bubble = true;
		for (j = 0; j < lenn - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_ints(array + j, array + j + 1);
				print_array(array, size);
				bubble = false;
			}
		}
		lenn--;
	}
}
