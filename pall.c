#include "monty.h"

/**
 * pall - function that prints all values on the stack starting from the top
 * @stack: pointer to struct of values
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
