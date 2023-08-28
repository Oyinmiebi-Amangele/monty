#include "monty.h"
/**
  *f_rotr - rotates the stack to the bottom
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *copy;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}

/*
 * f_stack - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	glob.lifo = 0;
}

/**
 * f_queue - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	glob.lifo = 1;
}

/**
 * addqueue - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 * Return: no return
 */
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *h;
	h = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (h)
	{
		while (h->next)
			h = h->next;
	}
	if (!h)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		h->next = new_node;
		new_node->prev = h;
	}
}

