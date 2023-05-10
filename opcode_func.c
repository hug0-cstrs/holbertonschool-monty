#include "monty.h"
/**
 * push - adds a new element to the top of stack
 * @stack: pointer to stack
 * @line_number: line number in file
 * @num: value to be pushed onto stack
 */
void push(stack_t **stack, unsigned int line_number, char *num)
{
	int n;

	if (num == NULL || !is_number(num))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	n = atoi(num);

	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;

	if (*stack == NULL)
		new_node->next = NULL;
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}


/**
 * is_number - Vérifie si la chaîne de caractères est un nombre entier.
 * @str: La chaîne de caractères à vérifier.
 * Return: 1 si la chaîne représente un nombre entier, 0 sinon.
 */
int is_number(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	int i = 0;

	if (str[0] == '-')
		i = 1;

	for (; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}

	return (1);
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
