#include "monty.h"

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	size_t j;
	int value;
	FILE *file;
	char opcode[10], line[256];
	stack_t *temp, *stack = NULL;
	unsigned int line_number = 1;
	instruction_t instructions[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"nop", nop}, {"add", add}, {"sub", sub},
		{"mul", mul}, {"div", divide}, {"mod", mod}
	};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		line[strcspn(line, "\n")] = '\0';
		if (strlen(line) == 0 || line[0] == '#')
		{
			continue;
		}
		if (sscanf(line, "%s %d", opcode, &value) == 2 && strcmp(opcode, "push") == 0)
			push(&stack, value);
		else
		{
			for (j = 0; j < sizeof(instructions) / sizeof(instructions[0]); j++)
			{
				if (strcmp(opcode, instructions[j].opcode) == 0)
				{
					instructions[j].f(&stack, line_number);
					break;
				}
			}
			if (j == sizeof(instructions) / sizeof(instructions[0]))
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
				fclose(file);
				return (EXIT_FAILURE);
			}
		}
		line_number++;
	}
	fclose(file);
	/* Clean up: free the remaining stack nodes */
	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
	return (0);
}
