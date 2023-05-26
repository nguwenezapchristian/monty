#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _getline - works like getline function
 * @lineptr: store the line
 * @n: size of the line
 * @stream: file
 * Return: ssize_t
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char *new_lineptr;
	ssize_t bufsize = 0;
	int c;
	ssize_t num_chars = 0;
	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return -1;
	}
	if (*lineptr == NULL || *n == 0)
	{
		*lineptr = malloc(bufsize = 128);
		if (*lineptr == NULL)
		{
			return -1;
		}
		*n = bufsize;
	}
	while ((c = fgetc(stream)) != EOF)
	{
		if (num_chars + 1 >= bufsize)
		{
			bufsize += 128;
			new_lineptr = realloc(*lineptr, bufsize);
			if (new_lineptr == NULL)
			{
				return -1;
			}
			*lineptr = new_lineptr;
			*n = bufsize;
		}
		(*lineptr)[num_chars++] = c;
		if (c == '\n')
		{
			break;
		}
	}
	if (num_chars == 0)
	{
		return -1;
	}
	(*lineptr)[num_chars] = '\0';
	return num_chars;
}
