#include "monty.h"

void push(stack_t **stack, int value)
{
	stack_t *newNode = (stack_t *)malloc(sizeof(stack_t));
    if (newNode == NULL)
    {
        printf("Error: Failed to allocate memory for new node\n");
        exit(EXIT_FAILURE);
    }

    newNode->n = value;
    newNode->next = NULL;

    if (*stack == NULL)
    {
        *stack = newNode;
    }
    else
    {
        newNode->next = *stack;
        *stack = newNode;
    }
}
