#include "main.h"

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
	char *token;
	stack_t stack = NULL;
	char **tokens = malloc(256 * sizeof(char));
	int i =0;
	unsigned int j = 1;
	void operation()
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
			printf("%s\n",tokens[i]);
			token = strtok(NULL, " \t\r\n\a");
			i++;
		}
		tokens[i] = NULL;
		j++;
	}
	}


