#include "monty.h"

/**
 * get_opc - function to handle the opcode
 * @stack: is a stack or queue
 * @arg: is a parameter
 * @item: is a parameter
 * @count: is a line command
 * Return: nothing
 */
int get_opc(stack_t **stack, char *arg, char *item, int count)
{
	int i = 0;
	/* Déclare un tableau de structures contenant des opcodes et des fonctions */
	instruction_t op[] = {
	    {"push", _push},
	    {"pall", _pall},
	    {"pint", _pint},
	    {"pop", _pop},
	    {"swap", _swap},
	    {"add", _add},
	    {"nop", _nop},
	    {"sub", _sub},
	    {"div", _div},
	    {"mul", _mul},
	    {"mod", _mod},
	    {"pchar", _pchar},
	    {"pstr", _pstr},
	    {"rotl", _rotl},
	    {"rotr", _rotr},
	    {NULL, NULL}};
	while (op[i].opcode)
	{ /* Compare l'opcode actuel avec celui en argument */
		if (!strcmp(arg, op[i].opcode))
		{
			if (!strcmp(arg, "push")) /* Si l'opcode est "push" */
			{			  /* Vérifie si le deuxième argument est un nombre */
				if (_isdigit(item) == 1)
					value = atoi(item); /*Convertit item en entier et stocke la dans 'value'*/
				else
					return (1);/*signale une erreur si le 2ème argument n'est pas un nombre*/
			}
			op[i].f(stack, (unsigned int)count);
			break; /* Sort de la boucle après avoir exécuté l'opcode */
		}
		i++;
	}
	/* Si l'opcode n'a pas été trouvé dans le tableau */
	if (!op[i].opcode)
		return (2);
	return (0);
}
