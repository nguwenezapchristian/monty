#include "monty.h"

/**
 * _realloc - reallocate the memory
 * @ptr: pointer to the prevoius allocated memory
 * @size: bytes to allocate
 * Return: pointer newly reallocated memory
 */

void *_realloc(void *ptr, ssize_t size)
{
	ssize_t i;
	void *new_ptr;
	char *old_ptr;
	char *new_ptr_char;
	
	if (size == 0)
	{
		free(ptr);
		return NULL;
	}
	new_ptr = malloc(size);
	if (new_ptr == NULL)
	{
		return NULL;
	}
	if (ptr != NULL)
	{
		old_ptr = (char *)ptr;
		new_ptr_char = (char *)new_ptr;
		for (i = 0; i < size; i++)
		{
			new_ptr_char[i] = old_ptr[i];
		}
		free(ptr);
	}
	return new_ptr;
}
