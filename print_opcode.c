#include "monty.h"

/**
 * _pall - print elements stack
 * @stack: is a parameter
 * @n: is value
 * Return: nothing
 */
void _pall(stack_t **stack, unsigned int n)
{
	stack_t *current = NULL;
	(void)n;

	current = *stack;

	while (current != NULL)
	{
		dprintf(STDOUT_FILENO, "%d\n", current->n);
		current = current->next;
	}
}

/**
 * _pint - prints the value at the top of the stack.
 * @stack: Stack list
 * @line_number: Number of the line
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !stack)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	else
		dprintf(STDOUT_FILENO, "%d\n", (*stack)->n);
}

/**
 * _pchar - prints the char at the top of the stack
 * of the stack by the top element of the stack
 * @stack: Stack list
 * @line_number: Number of line
 */

void _pchar(stack_t **stack, unsigned int line_number)
{
	int value;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}

	value = (*stack)->n;

	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}

	putchar(value);
	putchar('\n');
}
/**
 * _pstr - prints the string starting at the top of the stack
 * of the stack by the top element of the stack
 * @stack: Stack list
 * @line_number: Number of line
 */

void _pstr(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	int value;
	stack_t *tmp;

	if (*stack == NULL || stack == NULL)
	{
		putchar('\n');
		return;
	}

	tmp = *stack;
	while (tmp)
	{
		value = tmp->n;

		if (value <= 0 || value > 127)
			break;
		putchar(value);
		tmp = tmp->next;
	}
	putchar('\n');
}
