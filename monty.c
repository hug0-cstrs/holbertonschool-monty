#include "monty.h"

glob_t global = {NULL, NULL};
/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Arguments
 * Return: number of arguments.
 */
int main(int argc, char *argv[])
{
	if (argc == 2)
		handle_command(argv[1]);
	else
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
/**
 * handle_command - Read file
 * @argv: Arguments
 * Return: Nothing
 */
void handle_command(char *argv)
{
	int count = 0, result = 0;
	size_t bufsize = 0;
	char *arguments = NULL, *item = NULL;
	stack_t *stack = NULL;

	/* Ouvre le fichier donné en argument */
	global.fd = fopen(argv, "r");
	if (global.fd)
	{
		/* Lit chaque ligne du fichier et exécute les opcodes correspondants */
		while (getline(&global.line, &bufsize, global.fd) != -1)
		{
			count++; /* Incrémente le compteur de ligne */
			/* Récupère le premier argument de la ligne */
			arguments = strtok(global.line, " $\n");
			if (arguments == NULL)			 /* Ignore les lignes vides */
			{
				free(arguments);
				continue;
			}
			else if (*arguments == '$') /* Ignore les commentaires */
				continue;
			item = strtok(NULL, " $\n"); /*Récupère le 2ème argument de la ligne*/
			result = get_opc(&stack, arguments, item, count);
			if (result == 1) /* Si la fonction get_opc a renvoyé 1 */
				push_error(global.fd, global.line, stack, count);
			else if (result == 2) /* Si la fonction get_opc a renvoyé 2 */
				ins_error(global.fd, global.line, stack, arguments, count);
		}
		free(global.line);    /* Libère la mémoire allouée à la ligne courante */
		free_dlistint(stack); /* Libère la mémoire allouée à la pile/queue */
		fclose(global.fd);    /* Ferme le fichier */
	}
	else /* Si le fichier n'a pas pu être ouvert */
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
}
