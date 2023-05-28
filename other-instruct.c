#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: double pointer to the stack
 * @line_number: current line number in the file
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * swap - swaps the top elements of the stack
 * @stack: double pointer  to the stack
 * @line_number: current line number in the file
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	int temp;

	if (top == NULL || top->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = top->n;
	top->n = top->next->n;
	top->next->n = temp;
}
