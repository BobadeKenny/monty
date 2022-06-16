#include "main.h"

char *operand;

/**
 * parseFile - parses file
 * @fileName - name of file
 *
 */
void parseFile(char *fileName)
{
	FILE *file;
	char *line = NULL;
	size_t len=0;
	void (*operation)(stack_t**, unsigned int);
	stack_t *stack;
	char *token;
	char **tokens = malloc(256 * sizeof(char));
	int i =0;
	unsigned int j = 1;

	stack = NULL;
	if((file = fopen(fileName, "r")) == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fileName);
		exit(EXIT_FAILURE);
	}
	while((getline(&line, &len, file)) != -1)
	{
		token = strtok(line, " \t\r\n\a");
		while(token != NULL)
		{
			tokens[i] = token;
			token = strtok(NULL, " \t\r\n\a");
			i++;
		}
		tokens[i] = NULL;
		operation = get_opr(tokens[0]);
		if (operation == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s", j, tokens[0]);
			exit(EXIT_FAILURE);
		}
		operand = tokens[1];
		operation(&stack, j);
		j++;
	}
	}

/**
 * get_opr - get operation
 * @str: operator string
 *
 * Return: function
 *
*/
void (*get_opr(char *str))(stack_t**, unsigned int)
{
	instruction_t operations[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"mul", mul},
		{"div", div_op},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{NULL, NULL}
	};
	int i = 0;

	while (operations[i].opcode != NULL && strcmp((operations[i].opcode), str))
		i++;
	return (operations[i].f);
}
