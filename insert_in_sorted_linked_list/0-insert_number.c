#include <stdlib.h>
# include "lists.h"
/**
 * insert_node - Insserts a number into a sorted singly linked list.
 * @head: Pointer to a pointer to the head of the list.
 * @number: The value to be inserted into the list.
 *
 * Return: The address of the new node, or NULL if it fails.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node = malloc(sizeof(listint_t));
	listint_t *current;
	listint_t *prev = NULL;

	if (new_node == NULL)
		return (NULL);

	new_node->n = number;
	new_node->next = NULL;

	current = *head;
	

	/* Traverse the list to find the ccorrect position to inssert */
	while (current != NULL && current->n < number)
	{
		prev = current;
		current = current->next;
	}

	/* Insert the new_node */
	if (prev == NULL)
	{
		new_node->next = *head;
		*head = new_node;
	}
	else
	{
		prev->next = new_node;
		new_node->next = current;
	}
	return (new_node);
}
