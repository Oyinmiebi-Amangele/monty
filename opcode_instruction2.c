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

/**
 * f_add - adds the top two elements of tthe stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */

void f_add(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(glob.fdis);
		free(glob.content);
		free_list(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	ax = h->n + h->next->n;
	h->next->n = ax;
	*head = h->next;
	free(h);
}

/**
 * f_nop - nothing
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_nop(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}

/**
 * f_sub - subtract stack top elemt from second
 * @hed: stack head
 * f_sub - subtraction
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_sub(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(glob.fdis);
		free(glob.content);
		free_list(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	ax = h->next->n - h->n;
	h->next->n = ax;
	*head = h->next;
	free(h);
}

/**
 * f_div - divides the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return.
 */
void f_div(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(glob.fdis);
                free(glob.content);
                free_list(*head);
                exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
                fclose(glob.fdis);
                free(glob.content);
                free_list(*head);
                exit(EXIT_FAILURE);
	}
	ax = h->next->n / h->n;
	h->next->n = ax;
	*head = h->next;
	free(h);
}

