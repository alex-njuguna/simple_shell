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
* Return: void
*/
void execute_command(char *input)
{
	pid_t pid;
	int status, i = 0;
	char *token, *args[MAX_ARGS];

	token = strtok(input, " ");

	while (token != NULL && i < MAX_ARGS - 1)
	{
		args[i] = token;
		token = strtok(NULL, " ");
		i++;
	}

	args[i] = NULL;

	pid = fork();
	if (pid == 0)
	{
		execvp(args[0], args);
		fprintf(stderr, "Error: Failed to execute command.\n");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		fprintf(stderr, "Error: Failed to create child process.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			fprintf(stderr, "Error:'%s'status %d.\n", args[0], WEXITSTATUS(status));
		}
		else if (WIFSIGNALED(status))
		{
			fprintf(stderr, "Error:'%s' signal %d.\n", args[0], WTERMSIG(status));
		}
	}
}

/**
 * main - entry point
 * Return: 0
 */
int main(void)
{
	char *input;
	int isatty_mode = isatty(STDIN_FILENO);

	if (isatty_mode)
		printf("($) ");
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

		execute_command(input);

		if (isatty_mode)
			printf("($) ");

		free(input);
	}

	if (!isatty_mode)
		putchar('\n');

	return (EXIT_SUCCESS);
}
