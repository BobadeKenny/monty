#include "monty.h"

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

/**
 * pchar - print head of stack
 * @stack: stack
 * @line_number: file line number
 * Return: nothing
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * pstr - print elements in stack
 * @stack: stack
 * @line_number: file line number
 * Return: nothing
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	const stack_t *current = *stack;
	(void)line_number;

	while (current != NULL)
	{
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}
