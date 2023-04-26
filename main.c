#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include "main.h"

#define MAX_COMMAND_LENGTH 100

/**
 * main - entry point
 * Return: 0
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	size_t length;
	int status;

	while (1)
	{
		printf("$ ");
		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			break;
		}
		length = strcspn(command, "\n");
		if (length == 0)
		{
			continue;
		}
		command[length] = '\0';
		status = execute_command(command);
		if (status == -1)
		{
		printf("Error: command '%s' not found\n", command);
		}
	}
	return (0);
}

/**
 * execute_command - execute commands collected
 * @command: test par
 * Return: int
 */
int execute_command(char *command)
{
	pid_t pid = fork();
	char *args[10];

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		args[0] = command;
		args[1] = NULL;
		if (execvp(args[0], args) == -1)
		{
			return (-1);
		}
	}
	else
	{
	if (wait(NULL) == -1)
	{
		perror("wait");
		exit(EXIT_FAILURE);
	}
	}
	return (0);
}
