#include "main.h"

/**
 * builtins_ls -function to search match and execute builtin
 * @prog_data: the program's data structure
 * Return: Returns the return of the function executed,
 * otherwise returns -1
 **/

int builtins_ls(data_of_program *data)
{
	int iterator;
	builtins options[] = {
		{"exit", builtin_exit},
		{"help", builtin_help},
		{"cd", builtin_cd},
		{"alias", builtin_alias},
		{"env", builtin_environ},
		{"setenv", builtin_add_env},
		{"unsetenv", builtin_unadd_env},
		{NULL, NULL}
	};


	for (iterator = 0; options[iterator].builtin != NULL; iterator++)
	{

		if (str_compare(options[iterator].builtin, prog_data->command_name, 0))
		{

			return (options[iterator].function(prog_data));
		}

	}
	return (-1);
}
