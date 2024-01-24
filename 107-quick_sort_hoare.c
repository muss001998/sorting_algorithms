#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - this will Swap two integers in an array.
 * @a: This reps The first integer to swap.
 * @b: This reps The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - this will Order a subset of an array of integers
 *                   according to the hoare partition scheme.
 * @array:This reps The array of integers.
 * @size: This reps The size of the array.
 * @left: This reps The starting index of the subset to order.
 * @right: This reps The ending index of the subset to order.
 *
 * Return: This reps The final partition index.
 *
 * Description: this Uses the last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - this will Implement the quicksort algorithm through recursion.
 * @array: This reps An array of integers to sort.
 * @size: This repsThe size of the array.
 * @left: This reps The starting index of the array partition to order.
 * @right: This reps is The ending index of the array partition to order.
 *
 * Description: this Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - this will Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: This reps An array of integers.
 * @size: This reps The size of the array.
 *
 * Description: this Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
