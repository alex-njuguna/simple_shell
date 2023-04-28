#include "main.h"

/**
 * _print - output chars
 * @str: test par
 * Return: count int
 */
int _print(char *str)
{
	return (write(STDOUT_FILENO, str, str_len(str)));
}
/**
 * _printe - stderr
 * @str: test par
 * Return: count output
 */
int _printe(char *str)
{
	return (write(STDERR_FILENO, str, str_len(str)));
}

/**
 * _print_error - ..
 * @data: program's data'
 * @errorcode: error code
 * Return: count ouput
 */
int _print_error(int errorcode, data_of_program *data)
{
	char n_as_string[10] = {'\0'};

	num_to_str((long) data->exec_counter, n_as_string, 10);

	if (errorcode == 2 || errorcode == 3)
	{
		_printe(data->program_name);
		_printe(": ");
		_printe(n_as_string);
		_printe(": ");
		_printe(data->tokens[0]);
		if (errorcode == 2)
			_printe(": Illegal number: ");
		else
			_printe(": can't cd to ");
		_printe(data->tokens[1]);
		_printe("\n");
	}
	else if (errorcode == 127)
	{
		_printe(data->program_name);
		_printe(": ");
		_printe(n_as_string);
		_printe(": ");
		_printe(data->command_name);
		_printe(": not found\n");
	}
	else if (errorcode == 126)
	{
		_printe(data->program_name);
		_printe(": ");
		_printe(n_as_string);
		_printe(": ");
		_printe(data->command_name);
		_printe(": Permission denied\n");
	}
	return (0);
}
