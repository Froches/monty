#include "monty.h"

int main(void)
{
    stack_t *stack = NULL;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    stack_t *current = stack;
    while (current != NULL)
    {
        printf("%d ", current->n);
        current = current->next;
    }
    printf("\n");

    return 0;
}
