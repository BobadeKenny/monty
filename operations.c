#include "main.h"

/**
 * push - add to head of stack
 * @stack: stack
 * @line_number: file line number
 * Return: nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int n = line_number;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = *stack;
	new->prev = NULL;
	*stack = new;
}

/**
 * pall - print elements in stack
 * @stack: stack
 * @line_number: file line number
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	const stack_t *current = *stack;
	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - print head of stack
 * @stack: stack
 * @line_number: file line number
 * Return: nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - pop head of stack
 * @stack: stack
 * @line_number: file line number
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = curr->next;
}

/**
 * swap - swap top two elements of stack
 * @stack: stack
 * @line_number: file line number
 * Return: nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;

	if (curr == NULL || curr->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->n = curr->next->n;
	(*stack)->next->n = curr->n;
}

/**
 * add - add top two elements of stack
 * @stack: stack
 * @line_number: file line number
 * Return: nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	int n;

	if (curr == NULL || curr->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = curr->next->n + curr->n;
	pop(stack, line_number);
	pop(stack, line_number);
	curr->n = n;
	curr->next = *stack;
	curr->prev = NULL;
	*stack = curr;
}
