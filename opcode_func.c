#include "monty.h"

/**
 * push - adds a new element to the top of stack
 * @stack: pointer to stack
 * @line_number: instruction's line number
 * @num: value of the element to add
 */
void push(stack_t **stack, unsigned int line_number, char *num)
{
	stack_t *new;
	int i;

	if (num == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (i = 0; num[i] != '\0'; i++)
	{
		if (num[0] == '-' && i == 0)
			continue;
		if (isdigit(num[i]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = atoi(num);
	new->prev = NULL;
	new->next = NULL;

	if (*stack != NULL)
	{
		new->next = *stack;
		(*stack)->prev = new;
	}
	*stack = new;
}

/**
 * pop - removes the top element from stack
 * @stack: pointer to stack
 * @line_number: instruction's line number
 * Description: This function removes the top element of the stack, updates the
 * stack pointer, and frees the memory of the removed element.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to stack
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int tmp_a, tmp_b;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp_a = (*stack)->n;
	tmp_b = (*stack)->next->n;

	(*stack)->n = tmp_b;
	(*stack)->next->n = tmp_a;
}
