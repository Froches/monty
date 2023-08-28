#include "monty.h"

void divide(stack_t **stack, unsigned int line_number)
{
	int quotient;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	quotient = (*stack)->next->n / (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = quotient;
}
