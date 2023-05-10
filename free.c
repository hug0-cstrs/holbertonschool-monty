#include "monty.h"
/**
 * free_all - frees all allocated memory
 * @stack: pointer to stack
 * @line: pointer to line buffer
 * @fp: file pointer
 * Description: This function frees all allocated memory for the stack, line
 * buffer, and file pointer. It also closes the file.
 */

void free_all(stack_t **stack, char *line, FILE *fp)
{
	if (stack != NULL)
		free_stack(&stack);
	free(line);
	fclose(fp);
}

/**
 * free_stack - frees the top element of the stack
 * @stack: pointer to stack
 * Description: This function frees the memory of the top element of the stack
 */
void free_stack(stack_t **stack)
{
	stack_t *current;

	while (*stack != NULL)
	{
		current = *stack;
		*stack = (*stack)->next;
		free(current);
	}
}
