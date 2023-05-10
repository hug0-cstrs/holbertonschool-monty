#include "monty.h"

/**
 * main - open, reads and executes opcodes
 * @argc: number of arguments
 * @argv: argument vector
 * Return: succes
 */
int main(int argc, char **argv)
{
    FILE *fp;                             /* pointeur vers un fichier */
    stack_t *stack = NULL;                /* pointeur vers la pile */
    char *line = NULL, *opcode, *n;       /* pointeurs vers des chaînes de caractères */
    unsigned int line_number;             /* numéro de ligne */
    size_t len = 0;                       /* longueur de la ligne lue */
    ssize_t read;                         /* nombre de caractères lus */

    /* Vérification que le nombre d'arguments est correct */
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    /* Ouverture du fichier en lecture */
    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /* Initialise le numéro de ligne */
    line_number = 0;

    /* Boucle pour lire de chaque ligne du fichier */
    while ((read = getline(&line, &len, fp) != -1))
    {
        line_number++;

        /* Découpage de la ligne en opcode et argument(s) */
        opcode = strtok(line, DELIMITERS);

        /* Si la ligne est vide*/
        if (opcode == NULL)
		continue;

        /* Si l'opcode est "push", on appelle la fonction push */
        if (strcmp(opcode, "push") == 0)
        {
            n = strtok(NULL, DELIMITERS);
            push(&stack, line_number, n);
        }
        /* Sinon, on appelle la fonction correspondante à l'opcode */
        else
            get_op_code(opcode, &stack, line_number);
    }

    /* Libération de la mémoire allouée et fermeture du fichier */
    free_all(stack, line, fp);
    return (EXIT_SUCCESS);
}
