#include <stdio.h>
#include "sort.h"

/**
 * selection_sort - Sort an array of integers in ascending order
 * @array: pointer to array to be sorted
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t min;
	int temp;

	if (size > 2 && size != 2)
	{
		for (i = 0; i < size; i++)
		{
			min = i;
			for (j = i + 1; j < size; j++)
			{
				if (array[j] < array[min])
					min = j;
			}
			if (min != i)
			{
				temp = array[i];
				array[i] = array[min];
				array[min] = temp;
				print_array(array, size);
			}
		}
	}
}
