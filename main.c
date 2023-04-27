#include "main.h"

/**
* pipe_in - handle pipe input
* Return: void
*/
void pipe_in(void)
{
	char *buffer, separator;
	int fdout = 1;
	size_t sread, length = 0, err = -1;

	while ((sread = getline(&buffer, &length, stdin)) != err)
	{
		while (*buffer != '\n')
		{
			buffer += 1;
		}
		separator = ' ';
		write(fdout, &separator, sizeof(char));
		write(fdout, &separator, sizeof(char));
	}
}

/**
* delete_commands - empty commands
* @argv: commands to clear
*/
void delete_commands(char **argv)
{
	int i = 0;

	if (argv != NULL)
	{
		while (argv[i] != NULL)
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
}

/**
* main - entry point
* @ac: argument count
* @av: commands
* @envp: environment
* Return:0
*/
int main(int ac, char **av, char **envp)
{
	char *buff, *token, **argv = malloc(sizeof(char *));
	size_t sread, length = 0, i = 0, erno = -1;
	int fdout = 1, isterm, loop = 1, j = 0;
	(void)ac;
	(void)av;

	isterm = isatty(STDIN_FILENO);
	while (loop)
	{
		if (isterm)
		{
			myprintf(fdout, "#cisfun$ ");
			sread = getline(&buff, &length, stdin);
		}
		else
		{
			while (j < ac)
			{
				av[j] = av[j + 1];
				j++;
			}
			av[j] = NULL;
			execute_program(buff, av, &length, envp);
			return (0);
		}
		if (sread == erno)
		{
			show_error("\nEOF.\n", &buff, &length, argv);
			exit(0);
		}
		token = strtok(buff, " \n");
		if (token == NULL)
		{
			continue;
		}
		while (token != NULL)
		{
			argv[i] = malloc((string_length(token) + 1) * sizeof(char));
			argv[i] = token;
			i++;
			token = strtok(NULL, " \n");
		}
		argv[i] = NULL;
		i = 0;
		execute_program(buff, argv, &length, envp);
	}
	return (0);
}
