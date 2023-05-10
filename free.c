#include "monty.h"
/**
 *
 *
 */

void free_all(stack_t **stack, char *line, FILE *fp)
{
	if (stack != NULL)
		free_stack(&stack);
	free(line);
	fclose(fp);
}

void free(stack_t **stack)
{
	stack_t *current;

	while (*stack != NULL)
	{
		current = *stack;
		*stack = (*stack)->next;
		free(current);
	}
}
