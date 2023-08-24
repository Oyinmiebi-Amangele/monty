#include "main.h"

/**
 * f_push - add node to the stack
 * @head: stack head
 * @number: line_number
 * Return: no return
 */

void f_push(stack_t **head, unsigned int number)
{
	int n, j = 0, flag = 0;

	if (glob.arg)
	{
		if (glob.arg[0] == '-')
			j++;
		for (; glob.arg[j] != '\0'; j++)
		{
			if (glob.arg[j] > 57 || glob.arg[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", number);
			fclose(glob.fdis);
			free(glob.content);
			free_list(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", number);
		fclose(glob.fdis);
		free(glob.content);
		free_list(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(glob.arg);
	if (glob.lifo == 0)
		add_node(head, n);
	else
		add_queue(head, n);
}

/**
 * f_pall - print the stack
 * @head: stack head
 * @number: not used
 * Return: no return
 */

void f_pall(stack_t **head, unsigned int number))
{
	stack_t *h;
	(void)number;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
