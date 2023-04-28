#include "main.h"
/**
 * run_prog - function run prog
 * @data: program's data
 * Return: 0 or -1
 */
int run_prog(data_of_program *data)
{
	int retval = 0, status;
	pid_t pidd;

	retval = builtins1(data);
	if (retval != -1)
		return (retval);

	retval = locate_program(data);
	if (retval)
	{
		return (retval);
	}
	else
	{
		pidd = fork();
		if (pidd == -1)
		{
			perror(data->command_name);
			exit(EXIT_FAILURE);
		}
		if (pidd == 0)
		{
			retval = execve(data->tokens[0], data->tokens, data->env);
			if (retval == -1)
				perror(data->command_name), exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status))
				errno = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				errno = 128 + WTERMSIG(status);
		}
	}
	return (0);
}
