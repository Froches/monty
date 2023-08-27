#include "monty.h"

/**
 * add - function that adds the top two elements of the stack
 * @stack: struct containing info
 * @line_number: line number
 */

void add(stack_t **stack, unsigned int line_number)
{
	int operand1, operand2, result;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "Not enough ops %u.\n", line_number);
		exit(EXIT_FAILURE);
	}

	operand1 = (*stack)->n;
	operand2 = (*stack)->next->n;
	result = operand1 + operand2;

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
	(*stack)->prev = NULL;

	(*stack)->n = result;
}
