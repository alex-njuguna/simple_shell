#include "main.h"

/**
* get_input - collects input from the user
* Return: the user input
*/

char *get_input()
{
	char *input = (char *)malloc(MAX_CMD_LENGTH);

	fgets(input, MAX_CMD_LENGTH, stdin);
	return (input);
}

/**
* parse_input - parses the user input
* input: string of commands
* Return: split commands (tokens)
*/

char **parse_input(char *input)
{
	char **tokens = (char **)malloc(MAX_CMD_LENGTH * sizeof(char *));
	char *token;
	int idx = 0;

	token = strtok(input, " \n");
	while (token != NULL)
	{
		tokens[idx++] = token;
		token = strtok(NULL, " \n");
	}
	tokens[idx] = NULL;

	return (tokens);
}

/**
* execute - executes process
* args: list of commands
* Return: void
*/

void execute(char **args)
{
	extern char **environ;
	char **env = environ;
	pid_t pid = fork();

	if (strcmp(args[0], "exit") == 0)
	{
		exit(0);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		while (*env)
		{
			printf("%s\n", *env++);
		}
	}
	else
	{

		if (pid < 0)
		{
			perror("fork() failed");
			exit(1);
		}
		else if (pid == 0)
		{
			if (execvp(args[0], args) == -1)
			{
				perror("execvp() failed");
				exit(1);
			}
			exit(0);
		}
		else
		{
			wait(NULL);
		}
	}
}
