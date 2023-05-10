#include "monty.h"

/**
 * pall - prints all elements of the stack
 * @stack: pointer to stack
 * @line_number: instruction's line number
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL || stack == NULL)
		return;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to stack
 * @line_number: instruction's line number
 * Description: This function prints the value at the top of the stack, without
 * modifying the stack.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	int value;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = (*stack)->n;
	printf("%d\n", value);
}
