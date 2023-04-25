#include "main.h"

/**
 * main - entry point for all functions
 * Return: 0
 */
int main(void)
{
	char *input;
	char **args;

	while (1)
	{
		printf("#cisfun$ ");
		input = get_input();
		args = parse_input(input);
		execute(args);

		free(input);
		free(args);
	}

	return (0);
}
