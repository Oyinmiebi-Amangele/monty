#include "main.h"

/**
 * add_queue - add a node at the end of the doubly link list
 * @head: first position of the linked list
 * @n: data to store
 * Return: a doubly linked list
 */

stack_t *add_queue(stack_t **head, const int n)
{
	stack_t *temp, *ptr;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_glob();
		exit(EXIT_FAILURE);
	}
	temp->n = n;

	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}
	ptr = *head;
	while (ptr->next)
		ptr = ptr->next;
	temp->next = ptr->next;
	temp->prev = ptr;
	ptr->next = temp;
	return (ptr->next);
}

/**
 * add_node - add a node at the beginining of the doubly link list
 * @head: first position of linked list
 * @n: data to store
 * Return: a doubly linked list
 */

stack_t *add_node(stack_t **head, const int n)
{
	stack_t *temp;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_glob();
		exit(EXIT_FAILURE);
	}
	temp->n = n;

	if (*head == NULL)
	{
		temp->next = *head;
		tenp->prev = NULL;
		*head = temp;
		return (*head);
	}
	(*head)->prev = temp;
	temp->next = (*head);
	temp->prev = NULL;
	*head = temp;
	return (*head);
}

/**
 * free_list - frees the doubly linked list
 *
 * @head: head of the list
 * Return: no return
 */

void free_list(stack_t *head)
{
	stack_t *tmp;

	while ((tmp = head) != NULL)
	{
		head = head->next;
		free(tmp);
	}
}
