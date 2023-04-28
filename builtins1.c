#include "main.h"

/**
 * builtins1 - find matches and run
 * @data: struct for the program's data
 * Return: func exceecuted or -1
 */
int builtins1(data_of_program *data)
{
	int iterator;
	builtins options[] = {
		{"exit", myexit},
		{"help", myhelp},
		{"cd", mycd},
		{"alias", another_alias},
		{"env", show_env},
		{"setenv", create_env},
		{"unsetenv", destroy_env},
		{NULL, NULL}
	};

	for (iterator = 0; options[iterator].builtin != NULL; iterator++)
	{
		if (str_compare(options[iterator].builtin, data->command_name, 0))
		{
			return (options[iterator].function(data));
		}
	}
	return (-1);
}
