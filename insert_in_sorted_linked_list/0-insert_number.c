#include "lists.h"
/**
 * insert_node -  inserts a number into a sorted singly linked list.
 * @head: head of listint_t
 * @number: n of new node and position to insert node
 * Return: new node
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node, *current;

	node = malloc(sizeof(listint_t));
	if (!node)
		return (NULL);
	node->n = number;
	if (!head || !(*head))
	{
		node->next = NULL, *head = node;
	}
	else if (number < (*head)->n)
	{
		node->next = *head, *head = node;
	}
	else
	{
		current = *head;
		while (current->next && current->next->n < number)
			current = current->next;

		if (!current->next)
		{
			node->next = NULL, current->next = node;
		}
		else
		{
			node->next = current->next;
			current->next = node;
		}
	}
	return (node);
}
