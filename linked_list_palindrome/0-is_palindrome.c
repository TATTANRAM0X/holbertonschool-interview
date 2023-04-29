#include "lists.h"
/**
 * is_palindrome - checks if a singly linked list is a palindrome.
 * @head: head of listint_t to check if is a palindrome.
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome.
 */
int is_palindrome(listint_t **head)
{
	listint_t *cpy = *head;
	int buff[2048], i = 0, j = 0, mid;

	if (!head || (cpy && !cpy->next))
		return (1);
	while (cpy)
	{
		buff[i] = cpy->n;
		cpy = cpy->next;
		i++;
	}
	i--, mid = i / 2;
	while (i >= mid && j <= mid)
	{
		if (buff[j] != buff[i])
			return (0);
		i--, j++;
	}
	return (1);
}
