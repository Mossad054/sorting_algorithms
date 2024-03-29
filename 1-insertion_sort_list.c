#include "sort.h"

/**
 * swap_nds - Swap two nodes in a listint_t doubly-linked list.
 * @k: pointer to head of doubly-linked list.
 * @n1: A pointer to the first node to swap.
 * @n2: The second node to swap.
 */
void swap_nds(listint_t **k, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*k = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - Sort  doubly linked lst of integers
 *                       using the insertion sort algo.
 * @list:  pointer to head of doubly-linked list of integers.
 *
 * Description: prints list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = temp)
	{
		temp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nds(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
