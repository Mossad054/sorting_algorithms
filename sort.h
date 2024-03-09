#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * enum bool - enumeration of Boolean values.
 * @false: equals 0
 * @true: equals 1
 */
typedef enum bool
{
	false = 0,
	true
} bool;


/**
 * struct listint_s - doubly-linked list node
 *
 * @n: int stored in the node
 * @prev: points to the previous element of  list
 * @next: Pointer next element of  list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Printer help functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Sorting algorithms */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);

#endif /* SORT_H */
