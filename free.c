#include "monty.h"
/**
 * free_dlistint - Free a list.
 * @stack: Head node.
 * Return: Nothing.
 */

void free_dlistint(stack_t *stack)
{
	stack_t *current = NULL;

	current = stack;

	if (current != NULL)
	{
		free_dlistint(current->next);
		free(current);
	}
}

/**
 * cleanStack - Frees mallocs and close de files
 * @stack: Stack
 */
void cleanStack(stack_t **stack)
{
	stack_t *current = *stack;

	for (; current; current = *stack)
	{
		*stack = (*stack)->next;
		free(current);
	}
	fclose(global.fd);
	free(global.line);
}

