#include "monty.h"

/**
 * loop - a void function
 * @file: file stream
 * @string: char pointer
 * Return: returns nothing
*/

void loop(FILE *file, char *string)
{
	char opcode;
	size_t len = 0;
	ssize_t line_read; 
	int line_number = 0;


	while ((line_read = getline(&string, &len, file)) != -1)
	{
		line_number++;
		opcode = strtok(&line_buff, "\t\n"); 

		if (opcode == NULL || strlen(opcode) == 0)
		{
			continue;
		}
		fprint(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
