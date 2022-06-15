#include "main.h"

/**
 * main - monty
 * @argc: number of arguments
 * @argv: list of command line arguments
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	if (argc < 2)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	printf("%s", argv[0]);

	return (0);
}
