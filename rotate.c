#include "monty.h"

/**
 * _rotl - function that rotates the stack to the top
 * @stack: Stack list
 * @line_number: Number of line, unused
 */

void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *bottom = NULL;
	(void)line_number;

	bottom = *stack;
	if (!*stack || !(*stack)->next)
		return;

	while (bottom->next)
		bottom = bottom->next;

	/* Link the old top of the stack to the new bottom, and vice versa */
	bottom->next = *stack;
	(*stack)->prev = bottom;

	/* Move the new top of the stack to the second node */
	*stack = (*stack)->next;

	/* Detach the new top of the stack from its previous node */
	(*stack)->prev->next = NULL;

	/* Set the new top of the stack's "prev" pointer to NULL */
	(*stack)->prev = NULL;
}

/**
 * _rotr - function that rotates the stack to the bottom
 * @stack: Stack list
 * @line_number: Number of line, unused
 */

void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *bottom = NULL;
	(void)line_number;

	bottom = *stack;
	if (!*stack || !(*stack)->next)
		return;

	while (bottom->next)
		bottom = bottom->next;

	/* Link the old top of the stack to the new bottom, and vice versa */
	bottom->next = *stack;
	(*stack)->prev = bottom;

	/* Detach the new bottom of the stack from its previous node */
	bottom->prev->next = NULL;

	/* Set the new bottom of the stack's "prev" pointer to NULL */
	bottom->prev = NULL;

	/* Set the new bottom of the stack to be the new top of the stack */
	*stack = bottom;
}
