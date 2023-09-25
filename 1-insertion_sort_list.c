#include <stdlib.h>
#include "sort.h"
/**
 * insertion_sort_list - function that sorts a list using insertion
 * @list: this is a pointer to the head of a list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *j, *in, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (j = (*list)->next; j != NULL; j = tmp)
	{
		tmp = j->next;
		in = j->prev;
		while (in != NULL && j->n < in->n)
		{
			in->next = j->next;
			if (j->next != NULL)
				j->next->prev = in;
			j->prev = in->prev;
			j->next = in;
			if (in->prev != NULL)
				in->prev->next = j;
			else
				*list = j;
			in->prev = j;
			in = j->prev;

			print_list((const listint_t *)*list);
		}
	}
}
