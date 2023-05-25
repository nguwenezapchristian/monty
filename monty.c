#include <stdio.h>
#include <stdlib.h>

/**
 * main - monty bytecode interpreter
 * @argc: number of arguments
 * @argv: array of argument
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	(void)argv;
	
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	FILE *file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	fclose(file);
	return (0);
}
