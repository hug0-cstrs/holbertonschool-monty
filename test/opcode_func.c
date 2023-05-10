#include "monty.h"

/**
 * push - adds a new element to the top of stack
 * @stack: pointer to stack
 * @line_number: instruction's line number
 * @num: value of the element to add
 */
void push(stack_t **stack, unsigned int line_number, char *num)
{
    stack_t *new;  /* déclare un pointeur vers une nouvelle pile */
    int i;

    /* vérifie si la valeur à ajouter est nulle */
    if (num == NULL)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);  /* affiche un message d'erreur */
        exit(EXIT_FAILURE);  /* quitte le programme avec un code d'erreur */
    }

    /* boucle pour vérifier que chaque caractère de la valeur est un chiffre */
    for (i = 0; num[i] != '\0'; i++)
    {
        if (num[0] == '-' && i == 0)  /* ignore le signe négatif au début */
            continue;
        if (isdigit(num[i]) == 0)  /* vérifie si le caractère n'est pas un chiffre */
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);  /* affiche un message d'erreur */
            exit(EXIT_FAILURE);  /* quitte le programme avec un code d'erreur */
        }
    }

    /* alloue de la mémoire pour la nouvelle pile */
    new = malloc(sizeof(stack_t));
    if (new == NULL)  /* vérifie si l'allocation de mémoire a réussi */
    {
        printf("Error: malloc failed\n");  /* affiche un message d'erreur */
        exit(EXIT_FAILURE);  /* quitte le programme avec un code d'erreur */
    }

    /* initialise la valeur de la nouvelle pile */
    new->n = atoi(num);  /* convertit la valeur en entier */
    new->prev = NULL;
    new->next = NULL;

    /* ajoute la nouvelle pile au sommet de la pile existante */
    if (*stack != NULL)
    {
        new->next = *stack;
        (*stack)->prev = new;
    }
    *stack = new;
}

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
}
