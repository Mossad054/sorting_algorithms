#include "sort.h"

void swap_intgrs(int *i, int *j);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_intgrs - swap two ints in an array.
 * @i: The first integer to swap.
 * @j: The second integer to swap.
 */
void swap_intgrs(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

/**
 * lomuto_partition - order  subset of  array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array:  array of ints
 * @size:  size of  array.
 * @left: starting index of the subset
 * @right: ending index of the subset
 *
 * Return: final partition index
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pvt, abe, blw;

	pvt = array + right;
	for (abe = blw = left; blw < right; blw++)
	{
		if (array[blw] < *pvt)
		{
			if (abe < blw)
			{
				swap_intgrs(array + blw, array + abe);
				print_array(array, size);
			}
			abe++;
		}
	}

	if (array[abe] > *pvt)
	{
		swap_intgrs(array + abe, pvt);
		print_array(array, size);
	}

	return (abe);
}

/**
 * lomuto_sort - implement quicksort algo via recurs
 * @array: Array of int sorted
 * @size:  size of  array.
 * @left:  starting index of the array partition to order.
 * @right:  ending index of array partition to order
 *
 * Description: Use the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int prt;

	if (right - left > 0)
	{
		prt = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, prt - 1);
		lomuto_sort(array, size, prt + 1, right);
	}
}

/**
 * quick_sort - sort  array of ints in ascending
 *              order using quicksort algo
 * @array:array of integers
 * @size:  size of the array
 *
 * Description: use the lomuto partition scheme.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
