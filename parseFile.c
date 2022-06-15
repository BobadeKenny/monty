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
	size_t len = 0;

	if((file = fopen(fileName, "r")) == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fileName);
		exit(EXIT_FAILURE);
	}
	while((getline(&line, &len, file)) != -1)
	{
		printf("%s\n", line);
	}
}