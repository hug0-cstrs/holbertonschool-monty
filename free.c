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
