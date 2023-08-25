#include "monty.h"
/**
 * f_swap - swaps the top two elements of the stack
 *
 * @head: head of the linked list
 * @counter: line number
 * Return: no return
 */
void f_swap(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, ax;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(glob.fdis);
		free(glob.content);
		free_list(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	ax = h->n;
	h->n = h->next->n;
	h->next->n = ax;
}
