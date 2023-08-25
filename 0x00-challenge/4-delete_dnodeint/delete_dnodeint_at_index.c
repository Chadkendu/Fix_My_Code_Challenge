nclude "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete node at specific index from a list
 *
 * Description:
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 if valid, -1 if invalid
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *saved_head;
	dlistint_t *tmp;
	unsigned int p;

	if (*head == NULL)
	{
		return (-1);
	}
	saved_head = *head;
	p = 0;
	while (p < index && (*head)->next != NULL)
	{
		*head = (*head)->next;
		p++;
	}
	if (p != index)
	{
		*head = saved_head;
		return (-1);
	}
	if (index == 0)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
		if (tmp != NULL)
		{
			tmp->prev = NULL;
		}
	}
	else
	{
		tmp = *head;
		(*head)->prev->next = (*head)->next;
		if ((*head)->next != NULL)
			(*head)->next->prev = (*head)->prev;
		*head = saved_head;
		free(tmp);
	}
	return (1);
}
