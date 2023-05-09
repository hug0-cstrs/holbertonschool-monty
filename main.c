#include "monty.h"

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		execute_cmd(argv[1]);
	}
	else
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	return (0);
}


void execute_cmd(char *argv)
{
	/*int linecount = 0, result = 0;
	size_t bufsize = 0;
	char *arguments = NULL, *data = NULL;
	stack_t *stack = NULL;

	buffer.fd = fopen(argv, "r");
	
	if (buffer.fd)
	{
		while (getline(&buffer.line, &bufsize, buffer.fd) != -1)
		{
			linecount++;
			arguments = strtok(buffer.line, " \n\t\r");
			if (arguments == NULL)
			{
				free(arguments);
				continue;
			}
			data = strtok(NULL, " \n\t\r");
			result = get_opc(&stack, arguments, data, linecount);
			if (result == 1)
			{
				fprintf(stderr, "L%u: usage: push integer\n", linecount);
			}
				push_error(buffer.fd, buffer.line, stack, linecount);
			else if (result == 2)
			ins_error(buffer.fd, buffer.line, stack, arguments, linecount);
		}
	}
	else
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}*/
}


/*void get_opc()*/
