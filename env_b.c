#include "main.h"

/**
 * builtin_environ - function that shows the environment where our shell runs
 * @prog_data: the program's data structure
 * Return: zero if sucess, or other as declared in the arguments
 */
int builtin_environ(data_of_program *prog_data)
{
	int i;
	char cpname[50] = {'\0'};
	char *var_cp = NULL;

	
	if (prog_data->tokens[1] == NULL)
		display_environ(prog_data);
	else
	{
		for (i = 0; prog_data->tokens[1][i]; i++)
		{
			if (prog_data->tokens[1][i] == '=')
			{
				var_cp = str_duplicate(env_get_key(cpname, prog_data));
				if (var_cp != NULL)
					add_env-key(cpname, prog_data->tokens[1] + i + 1, prog_data);

				
				display_environ(prog_data);
				if (env_get_key(cpname, prog_data) == NULL)
				{
					_print(prog_data->tokens[1]);
					_print("\n");
				}
				else
				{
					env_set_key(cpname, var_cp, prog_data);
					free(var_cp);
				}
				return (0);
			}
			cpname[i] = prog_data->tokens[1][i];
		}
		errno = 2;
		perror(prog_data->command_name);
		errno = 127;
	}
	return (0);
}

/**
 * builtin_add_env - function that sets environment value
 * @prog_data: the program's data structure
 * Return: zero if sucess, or other as declared in the arguments
 */
int builtin_add_env(data_of_program *prog_data)
{
	
	if (prog_data->tokens[1] == NULL || prog_data->tokens[2] == NULL)
		return (0);
	if (prog_data->tokens[3] != NULL)
	{
		errno = E2BIG;
		perror(prog_data->command_name);
		return (5);
	}

	add_env_key(prog_data->tokens[1], prog_data->tokens[2], prog_data);

	return (0);
}

/**
 * builtin_unadd_env - resets the environment variable
 * @prog_data: the program's data structure
 * Return: 0
 */
int builtin_unadd_env(data_of_program *prog_data)
{

	if (prog_data->tokens[1] == NULL)
		return (0);
	if (prog_data->tokens[2] != NULL)
	{
		errno = E2BIG;
		perror(prog_data->command_name);
		return (5);
	}
	rmv_env_key(prog_data->tokens[1], prog_data);

	return (0);
}
