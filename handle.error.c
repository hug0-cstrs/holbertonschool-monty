#include "monty.h"

/**
 * push_error - handle push error
 * @fd: is a file desciptor
 * @line: is a buffer
 * @stack: is a stack or queue
 * @count: is a line command
 */
void push_error(FILE *fd, char *line, stack_t *stack, int count)
{
	fprintf(stderr, "L%u: usage: push integer\n", count);
	fclose(fd);
	free(line);
	free_dlistint(stack);
	exit(EXIT_FAILURE);
}

/**
 * ins_error - Handle instruction error
 * @fd: is a file descriptor
 * @line: is a buffer
 * @stack: is a stack or queue
 * @count: is a line command
 * @item: number
 */
void ins_error(FILE *fd, char *line, stack_t *stack, char *count, int item)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", item, count);
	fclose(fd);
	free(line);
	free_dlistint(stack);
	exit(EXIT_FAILURE);
}
