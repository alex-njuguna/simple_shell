#include "main.h"
/**
 * execute_prog - function that executes a command
 * @prog_data: the program's data structure
 * Return: o if sucess, otherwise, -1.
 */
int execute_prog(data_of_program *prog_data)
{
	int ret_val = 0, status;
	pid_t pidd;

	
	ret_val = builtins_list(prog_data);
	if (ret_val != -1)
		return (ret_val);

	
	ret_val = find_program(prog_data);
	if (ret_val)
	{
		return (ret_val);
	}
	else
	{
		pidd = fork();
		if (pidd == -1)
		{
			perror(prog_data->command_name);
			exit(EXIT_FAILURE);
		}
		if (pidd == 0)
		{
			ret_val = execve(prog_data->tokens[0], prog_data->tokens, prog_data->env);
			if (ret_val == -1)
				perror(prog_data->command_name), exit(EXIT_FAILURE);
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
