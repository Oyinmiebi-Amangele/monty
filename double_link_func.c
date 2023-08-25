#include "main.h"
/**
 * add_queue - Adds a new node at the end of a queue
 * @head: Pointer to a pointer to the head node of the queue
 * @n: Value to be added to the new node
 *
 * Return: Address of the newly added node, or NULL on failure
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
 * add_node - Adds a new node at the beginning of a linked list
 * @head: Pointer to a pointer to the head node of the linked list
 * @n: Value to e added to the new node.
 *
 * Return: Address of the newly added node, or NULL on failure
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
 * free_list - Frees all nodes in a linked list
 * @head: pointer to the head node of the linked list
 *
 * Description: Frees each node in the linked list and sets the head
 * to NULL
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

