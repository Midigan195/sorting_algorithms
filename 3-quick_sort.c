#include <stddef.h>
#include "sort.h"

/**
 * swap - swaps two integers in an array
 * @array: pointer to the array
 * @a: index of the first integer
 * @b: index of the second integer
 */
void swap(int *array, int a, int b)
{
	int temp = array[a];

	array[a] = array[b];
	array[b] = temp;
}

/**
 * partition - partition of subarry for Quick Sort
 * @array: pointer to the array to sort
 * @low: strat of sub array
 * @high: end of sub array
 * @size: size of array
 * Return: Index of the pivot element
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(array, i, j);
				print_array(array, size);
			}
		}
	}

	if (i + 1 != high)
	{
		swap(array, i + 1, high);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort_recursive - recursively perform Quick Sort
 * @array: pointer to array
 * @low: start of sub array
 * @high: end of sub array
 * @size: size of the array
 */
void quicksort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high, size);
		quicksort_recursive(array, low, pivot_index - 1, size);
		quicksort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers using Quick Sort
 * @array: pointer to the array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	quicksort_recursive(array, 0, size - 1, size);
}

