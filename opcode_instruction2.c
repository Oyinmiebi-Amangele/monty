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
<<<<<<< HEAD
 * f_sub - subtract stack top elemt from second
 * @hed: stack head
=======
 * f_sub - subtraction
 * @head: stack head
>>>>>>> d015f34804ae6f781547926643e76f2ecf29b7f5
 * @counter: line_number
 * Return: no return
 */
void f_sub(stack_t **head, unsigned int counter)
{
<<<<<<< HEAD
	stack_t *h;
	int len = 0, ax;
	
	h = *head;
	while (h)
        {
                h = h->next;
                len++;
        }
	if (len < 2)
=======
	stack_t *aux;
	int sus, node;

	aux = *head;
	for (node = 0; aux != NULL; node++)
		aux = aux->next;
	if (node < 2)
>>>>>>> d015f34804ae6f781547926643e76f2ecf29b7f5
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(glob.fdis);
		free(glob.content);
		free_list(*head);
		exit(EXIT_FAILURE);
	}
<<<<<<< HEAD
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


=======
	aux = *head;
	sus = aux->next->n - aux->n;
	aux->next->n = sus;
	*head = aux->next;
	free(aux);
}
>>>>>>> d015f34804ae6f781547926643e76f2ecf29b7f5
