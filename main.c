#include "main.h"

/**
* read_input - read input from user
* Return: input or null
*/
char *read_input(void)
{
	char *input = malloc(sizeof(char) * MAX_LENGTH);
	size_t input_size = 0;

	if (getline(&input, (size_t *) &input_size, stdin) == -1)
	{
		free(input);
		return (NULL);
	}

	return (input);
}

/**
* execute_command - executes commands provided
* @input: pointer to list of commands
* @argv: array vector of commands
* Return: void
*/
void execute_command(char *input, char *argv[])
{
pid_t pid = fork();
int status;
char *args[4];

if (pid == 0)
{
args[0] = "/bin/sh";
args[1] = "-c";
args[2] = input;
args[3] = NULL;
execv(args[0], args);
fprintf(stderr, "%s: %d: %s: not found\n", argv[0], __LINE__, input);
exit(EXIT_FAILURE);
}
else
{
waitpid(pid, &status, 0);
if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
{
fprintf(stderr, "%s:%d:%s:%d", argv[0], __LINE__, input, WEXITSTATUS(status));
}
else if (WIFSIGNALED(status))
{
fprintf(stderr, "%s: %d: %s: %d", argv[0], __LINE__, input, WTERMSIG(status));
}
}
}

/**
* main - entry point
* @argc: arg count
* @argv: arg list
* Return: 0
*/
int main(int argc, char *argv[])
{
	char *input;
	int isatty_mode = isatty(STDIN_FILENO);

	if (isatty_mode)
		myprintf("($) ");
	if (argc > 1)
		myprintf("You have listed %d commands.", argc - 1);
	while (1)
	{
		if (isatty_mode)
			input = read_input();
		else
		{
			input = malloc(sizeof(char) * MAX_LENGTH);
			if (fgets(input, MAX_LENGTH, stdin) == NULL)
			break;
		}
		input[mystrcspn(input, "\n")] = '\0';

		if (mystrcmp(input, "exit") == 0)
		{
			free(input);
			break;
		}

		execute_command(input, argv);
		if (isatty_mode)
			myprintf("($) ");

		free(input);
	}

	if (!isatty_mode)
		myputchar('\n');

	return (EXIT_SUCCESS);
}
