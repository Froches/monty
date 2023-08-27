#include "monty.h"

/**
 * push - function that pushes an element to the stack
 * @stack: pointer to struct of values
 * @value: Value to be pushed to the stack
 */
void push(stack_t **stack, unsigned int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Memory allocation failed.\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
