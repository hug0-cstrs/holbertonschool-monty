#include "monty.h"

/**
 * _add - function add two integer
 * @stack: Stack list
 * @line_number: Number of the line
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;
	int sum = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	sum = current->n + current->next->n;
	current->next->n = sum;
	_pop(stack, line_number);
}

/**
 * _sub - subtracts the top element of the stack from the second.
 * @stack: Stack list
 * @line_number: Number of line
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int sub = 0;

	if (!current || !current->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	sub = current->next->n - current->n;
	current->next->n = sub;
	_pop(stack, line_number);
}

/**
 * _div - divides the second top element of the stack
 * by the top element of the stack
 * @stack: Stack list
 * @line_number: Number of line
 */

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;
	int div = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	div = current->next->n / current->n;
	current->next->n = div;
	_pop(stack, line_number);
}

/**
 * _mul - multiplies the second top element of the stack
 * with the top element of the stack
 * @stack: Stack list
 * @line_number: Number of line
 */

void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;
	int mul = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	mul = current->next->n * current->n;
	current->next->n = mul;
	_pop(stack, line_number);
}

/**
 * _mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack
 * @stack: Stack list
 * @line_number: Number of line
 */

void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;
	int mod = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	mod = current->next->n % current->n;
	current->next->n = mod;
	_pop(stack, line_number);
}
