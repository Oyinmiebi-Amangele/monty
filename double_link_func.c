#include "monty.h"
/**
 * add_queue - Adds a new node at the end of a queue
 * @head: pointer to a pointer to the head node of the queue
 * @n: value to be added to the new node
 *
 * Return: Address of the newly node, or NULL on failure
 */

stack_t *add_queue(stack_t **head, const int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	stack_t *current;

	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;

	current = *head;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	while (current->next != NULL)
	{
		current = current->next;
	}

	current->next = new_node;
	new_node->prev = current;
	return (new_node);
}

/**
 * add_node - adds a new node at the beginning of a linked list
 * @head: Pointer to a pointer to the head node of the linked list
 * @n: Value to be added to the new node.
 *
 * Return: Address of the newly added node, or NULL on failure.
 */

stack_t *add_node(stack_t **head, const int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
		return (NULL);
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;

	if (*head != NULL)
	{
		(*head)->prev = new_node;
	}
	*head = new_node;
	return (new_node);
}

/**
 * free_list - frees all nodes in a linked list
 * @head: pointer to the head node of the linked list
 *
 * Description: frees each node in the linked list and set the head to NULL.
 */
void free_list(stack_t *head)
{
	while (head != NULL)
	{
		stack_t *next_node = head->next;

		free(head);
		head = next_node;
	}
}
