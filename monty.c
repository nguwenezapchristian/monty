#include "monty.h"
#include <stdio.h>

/**
 * main - monty bytecode interpreter
 * @argc: number of arguments
 * @argv: array of argument
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	int i;
	char *tokens[1024];
	FILE *file;
	char* token;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	char *line = NULL;
	size_t line_size = 0;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (_getline(&line, &line_size, file) != -1)
	{
		line_number++;
		token = strtok(line, " \t\n");

		i = 0;
		while (token != NULL)
		{
			tokens[i] = token;
			i++;
			token = strtok(NULL, " \t\n");
		}

		if (i > 0 && tokens[0][0] != '#')
		{
			if (strcmp(tokens[0], "push") == 0)
				push(&stack, line_number, tokens);
			else if (strcmp(tokens[0], "pall") == 0)
				pall(&stack, line_number);
			else
			{
				printf("L%d: unknown instruction %s\n", line_number, tokens[0]);
				exit(EXIT_FAILURE);
			}
		}
	}
	free(line);
	fclose(file);
	return (0);
}
