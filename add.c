#include "monty.h"


void add(stack_t **stack, unsigned int line_number)
{
	int operand1, operand2, result;
	stack_t *temp;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "Not enough operands for addition at line %u.\n", line_number);
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
