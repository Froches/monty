#include "monty.h"

void divi(stack_t **stack, unsigned int line_number)
{
	int quotient;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too shprt\n", line_number);
		exit(EXIT_FAILURE);
	}

	quotient = (*stack)->next->n / (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = quotient;
}

void mul(stack_t **stack, unsigned int line_number)
{
	int product;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too shprt\n", line_number);
		exit(EXIT_FAILURE);
	}

	product = (*stack)->n * (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->n = product;
}

void mod(stack_t **stack, unsigned int line_number)
{
	int remainder;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too shprt\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	remainder = (*stack)->next->n % (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = remainder;
}
