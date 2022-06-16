#include "main.h"

/**
 * mod - multiply top two elements of stack
 * @stack: stack
 * @line_number: file line number
 * Return: nothing
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	int n;

	if (curr == NULL || curr->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = curr->next->n % curr->n;
	pop(stack, line_number);
	pop(stack, line_number);
	curr->n = n;
	curr->next = *stack;
	curr->prev = NULL;
	*stack = curr;
}