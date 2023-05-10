#include "monty.h"

/**
 * main - open, reads and executes opcodes
 * @argc: number of arguments
 * @argv: argument vector
 * Return: succes
 */
int main(int argc, char **argv)
{
	FILE *fp;
	stack_t *stack = NULL;
	char *line = NULL, *opcode, *n;
	unsigned int line_number;
	size_t len = 0;
	ssize_t read;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	line_number = 0;
	while ((read = getline(&line, &len, fp)) != -1)
	{
		line_number++;
		opcode = strtok(line, DELIMITERS);
		if (opcode == NULL)
			continue;

		if (strcmp(opcode, "push") == 0)
		{
			n = strtok(NULL, DELIMITERS);
			push(&stack, line_number, n);
		}
		else
			get_op_code(opcode, &stack, line_number);
	}
	free_all(&stack, line, fp);
	return (EXIT_SUCCESS);
}

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
		free_stack(stack);
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
	if (stack == NULL || *stack  == NULL)
		return;

	stack_t *current;

	while (*stack != NULL)
	{
		current = *stack;
		*stack = (*stack)->next;
		free(current);
	}
}
