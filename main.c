#include "monty.h"

/**
 * main - Entry point for the Monty interpreter
 * @argc: Number of command line arguments
 * @argv: Array of command line arguments
 *
 * Description: Reads Monty bytecode from a file and executes instructions.
 * Return: 0 on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;
	unsigned int line_number = 1;
	char opcode[5];
	int value;

	if (argc != 2)
		usage_error(argv[0]);

	file = fopen(argv[1], "r");
	if (file == NULL)
		file_open_error(argv[1]);
	while (fscanf(file, "%4s", opcode) == 1)
	{
		if (strcmp(opcode, "push") == 0)
		{
			if (fscanf(file, "%d", &value) != 1)
				push_usage_error(line_number);
			push(&stack, line_number, value);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack, line_number);
		}
		else if (strcmp(opcode, "pint") == 0)
		{
			pint(&stack, line_number);
		}
		else
		{
			unknown_opcode_error(line_number, opcode);
		}
		line_number++;
	}

	fclose(file);
	free_stack(&stack);

	return (0);
}

/**
 * usage_error - Print usage error message and exit with failure status
 * @prog_name: Name of the program
 */
void usage_error(char *prog_name)
{
	fprintf(stderr, "Usage: %s <file>\n", prog_name);
	exit(EXIT_FAILURE);
}

/**
 * file_open_error - Print file open error message and exit with failure status
 * @file_name: Name of the file
 */
void file_open_error(char *file_name)
{
	fprintf(stderr, "Error: Can't open file %s\n", file_name);
	exit(EXIT_FAILURE);
}

/**
 * push_usage_error - Print push usage error message
 * @line_number: Line number in the file
 */
void push_usage_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * unknown_opcode_error - Print unknown opcode error message and exit
 * with failure status
 * @line_number: Line number in the file
 * @opcode: Unknown opcode
 */
void unknown_opcode_error(unsigned int line_number, char *opcode)
{
	fprintf(stderr, "L%u: unknown instruction \"%s\"\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

