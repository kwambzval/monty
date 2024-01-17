#include "monty.h"
/**
 * push - pushes an element to the stack.
 * @stack: double pointer to the top of the stack.
 * @line_number: line number from script file.
 * @n: integer to push onto stack.
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number, const int n)
{
	stack_t *new;
	void(line_number);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->prev = NULL;
	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * pall - prints all values on the stack, starting from the top.
 * @stack: double pointer to the top of the stack.
 * @line_number: line number from script file.
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;
	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

