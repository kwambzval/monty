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
	stack_t *new_node;

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: Error: Stack is NULL\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "L%u: Error: malloc failed\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
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
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

