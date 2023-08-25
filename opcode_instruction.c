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

