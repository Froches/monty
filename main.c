#include "monty.h"

int main()
{
	size_t i, j;
	unsigned int line_number;
	char opcode[10];
	instruction_t *instr;

	stack_t *stack = NULL;
	instruction_t instructions[] = {
		{"push", push},
		{"add", add},
		{"pall", pall}
	};

	char *input[] = {"push 5", "push 3", "pall"};
	line_number = 1;

	for (i = 0; i < sizeof(input) / sizeof(input[0]); i++)
	{
		sscanf(input[i], "%s", opcode);

		instr = NULL;
		for (j = 0; j < sizeof(instructions) / sizeof(instructions[0]); j++)
		{
			if (strcmp(opcode, instructions[j].opcode) == 0)
			{
				instr = &instructions[j];
				break;
			}
		}
		if (instr == NULL)
		{
			fprintf(stderr, "Unknown opcode: %s at line %u\n", opcode, line_number);
			exit(EXIT_FAILURE);
		}
		instr->f(&stack, line_number);
		line_number++;
	}
	/* printf("Result: %d\n", stack->n); */
	printf("%d\n", stack->n);

	while (stack != NULL)
	{
		stack_t *temp = stack;
		stack = stack->next;
		free(temp);
	}
	return (0);
}
