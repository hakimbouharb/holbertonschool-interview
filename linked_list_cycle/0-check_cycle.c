#include "lists.h"


/**
 * check_cycle - check cycle in linked list
 * @list: linked list
 * Return: 0 if there is a cycle 1 if not
 */

int check_cycle(listint_t *list)
{
	listint_t *turtle;
	listint_t *rabbit;

	if (list == NULL)
		return (0);

	turtle = list;
	rabbit = list->next;

	while (turtle != NULL && rabbit != NULL && rabbit->next != NULL)
	{
		if (turtle == rabbit)
			return (1);
		turtle = turtle->next;
		rabbit = rabbit->next->next;
	}
	return (0);
}
