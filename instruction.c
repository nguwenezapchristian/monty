#include "monty.h"

/**
 * is_integer - checks if a string represents an integer
 * @str: string to check
 * Return: 1 if the string represents an integer, 0 otherwise
 */

int is_integer(const char *str)
{
	int i = 0;

	if (str == NULL || *str == '\0')
		return 0;
	if (str[0] == '-' || str[0] == '+')
		i = 1;
	for (; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the stack
 * @line_number: current line number in the file
 */

void push(stack_t **stack, unsigned int line_number, char **tokens)
{
	stack_t *nnode;
	int data;

	if (tokens[1] == NULL || !is_integer(tokens[1]))
	{
		printf("L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	data = atoi(tokens[1]);
	nnode = malloc(sizeof(stack_t));
	if (nnode == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	nnode->n = data;
	nnode->prev = NULL;
	nnode->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = nnode;
	}
	*stack = nnode;
}
/**
 * pop - removes the top element of the stack
 * @stack: double pointer to the stack
 * @line_number: current line number in the file
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * pall - print all data in stack
 * @stack: pointer to the stack
 * @line_number: current line number in the file
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
