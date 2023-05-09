#include "monty.h"

/**
 * new_Node - creates a new node
 * @n: data of the new node
 * Return: pointer to new node
 */
stack_t *new_Node (int n)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->prev = NULL;
	new->next = NULL;

	return (new);
}
/**
 * _push - creates a new node at the beginning of stack
 * @stack: double pointer to the stack
 * @line_number: line number of the command
 */

void push(stack_t **h /*)unsigned int ln*/)
{
	stack_t *new;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(37);
	}
	new->prev = NULL;
	if (*h == NULL)
	{
		new->next = NULL;
	}
	else
	{
		(*h)->prev = new;
		new->next = *h;
	}
	*h = new;
}
/**
 * _pall - print all the values of the stack
 * @stack: double pointer to the stack
 * @n: data to print
 * Return: nothing
 */

void _pall(stack_t **stack /*,unsigned int n*/)
{
	stack_t *temp = NULL;

	temp = *stack;

	while(temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	free(temp);
}
