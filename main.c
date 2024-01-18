#include "monty.h"

/**
 * main - monty interperter
 * @ac: the number of arguments
 * @av: the arguments
 * Return: void
 */
int main(int ac, char *av[])
{
	stack_t *stack = NULL;
	char *string = NULL;
	FILE *file;
	

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (file  == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}


	loop(file, string);
	execute(string, stack);
	free_list(string);
	fclose(file);
	return (0);
}

/**
 * execute - executes opcodes
 * @string: contents of file
 * @stack: the list
 * Return: void
 */

void execute(char *string, stack_t *stack)
{
	int ln, n, i;

	instruction_t st[] = {
		{"pall", pall},
		{"pint", pint},
		{"add", add},
		{"swap", swap},
		{"pop", pop},
		{"null", NULL}
	};

	for (ln = 1, n = 0; string[n + 1]; n++, ln++)
	{
		if (_strcmp("push", string[n]))
			push(&stack, ln, pushint(string[n], ln));
		else if (_strcmp("nop", string[n]))
			;
		else
		{
			i = 0;
			while (!_strcmp(st[i].opcode, "null"))
			{
				if (_strcmp(st[i].opcode, string[n]))
				{
					st[i].f(&stack, ln);
					break;
				}
				i++;
			}
			if (_strcmp(st[i].opcode, "null") && !_strcmp(string[n], "\n"))
			{
				fprintf(stderr, "L%u: unknown instruction %s", ln, string[n]);
				if (!nlfind(string[n]))
					fprintf(stderr, "\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	free_stack(stack);
}
