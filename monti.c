#include "monty.h"

/**
 * main - function body
 * @argc: character counter
 * @argv: character value
 * Return: returns zero
*/



int main(int argc, char *argv[])
{
    char *line_buff = NULL;
    char *filepath;
    FILE *file;

    if (argc != 2)
    {
        fprint(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    filepath = argv[1];
    file = fopen(filepath, 'r');

    if (file == NULL)
    {
        fprint(stderr, "Error: Can't open file %s\n", filepath);
        exit(EXIT_FAILURE);

    }

    loop(file, line_buff);


    free(line_buff);
    fclose(file);
    exit(EXIT_FAILURE);
    return (0);

}

/**
 * loop - a void function
 * @argv: character pointer
 * Return: returns nothing
*/

void loop(FILE *file, char *line_buff)
{
    char *opcode;

    size_t len = 0;
    ssize_t line_read;
    int line_number = 0;


    while ((line_read =  getline(&line_buff, &len, file)) != -1)
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
