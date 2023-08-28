#include "monty.h"

/**
 * f_push - pushes an element to the stack
 *
 * @head: head of the linked list
 * @number: line number
 * Return: no return
 */
void f_push(stack_t **head, unsigned int number)
{
	int n, j;

	if (!glob.arg)
	{
		dprintf(2, "L%u: ", number);
		dprintf(2, "usage: push integer\n");
		free_glob();
		exit(EXIT_FAILURE);
	}

	for (j = 0; glob.arg[j] != '\0'; j++)
	{
		if (!isdigit(glob.arg[j]) && glob.arg[j] != '-')
		{
			dprintf(2, "L%u: ", number);
			dprintf(2, "usage: push integer\n");
			free_glob();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(glob.arg);

	if (glob.lifo == 1)
		add_node(head, n);
	else
		add_queue(head, n);
}

/**
 * f_pall - prints all values on the stack
 *
 * @head: head of the linked list
 * @number: line numbers
 * Return: no return
 */
void f_pall(stack_t **head, unsigned int number)
{
	stack_t *aux;
	(void)number;

	aux = *head;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

/**
 * f_pint - prints the value at the top of the stack
 *
 * @head: head of the linked list
 * @counter: line number
 * Return: no return
 */
void f_pint(stack_t **head, unsigned int counter)
{
	(void)counter;

	if (*head == NULL)
	{
		dprintf(2, "L%u: ", counter);
		dprintf(2, "can't pint, stack empty\n");
		free_glob();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * f_pop - removes the top element of the stack
 *
 * @head: head of the linked list
 * @counter: line number
 * Return: no return
 */
void f_pop(stack_t **head, unsigned int counter)
{
	stack_t *ax;

	if (head == NULL || *head == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", counter);
		free_glob();
		exit(EXIT_FAILURE);
	}
	ax = *head;
	*head = (*head)->next;
	free(ax);
}
<<<<<<< HEAD
=======

>>>>>>> d015f34804ae6f781547926643e76f2ecf29b7f5
