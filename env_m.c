#include "main.h"

/**
 * get_env_val - function that ets the environment variabl value
 * @key_var: to the environment variable requested
 * @prog_data: the program's data structure
 * Return: pointer to value of the variable or NULL if it doesn't exist
 */
char *get_env_val(char *key_var, data_of_program *prog_data)
{
	int i, key_len = 0;

	
	if (key_var == NULL || prog_data->env == NULL)
		return (NULL);

	
	key_len = str_length(key_var);

	for (i = 0; prog_data->env[i]; i++)
	{
		if (str_compare(key_var, prog_data->env[i], key_len) &&
		 prog_data->env[i][key_len] == '=')
		{
			return (prog_data->env[i] + key_len + 1);
		}
	}

	return (NULL);
}

/**
 * add_env_key - function that sets the value of the environment variable
 * or creates one if does not exist.
 * @key_name: the name of the variable to be set
 * @new_value: the  new value
 * @prog_data: the program's data structure
 * Return: 1 if set parameters are NULL, 2 if error, 0 if sucess
 */

int add_env_key(char *key_name, char *new_value, data_of_program *prog_data)
{
	int i, key_len = 0, new_key = 1;

	
	if (key_name == NULL || new_value == NULL || prog_data->env == NULL)
		return (1);

	
	key_len = str_length(key_name);

	for (i = 0; prog_data->env[i]; i++)
	{
		if (str_compare(key_name, prog_data->env[i], key_len) &&
		 prog_data->env[i][key_len] == '=')
		{
			new_key = 0;
			
			free(prog_data->env[i]);
			break;
		}
	}

	prog_data->env[i] = str_concat(str_duplicate(key), "=");
	prog_data->env[i] = str_concat(data->env[i], value);

	if (new_key)
	{
		prog_data->env[i + 1] = NULL;
	}
	return (0);
}

/**
 * rmv_env_key - function that removes key from the environment
 * @key_name: the key to be removed
 * @prog_data: the sructure of the program's data
 * Return: 1 if success, 0 if key does not exist
 */
int rmv_env_key(char *key_name, data_of_program *prog_data)
{
	int i, key_len = 0;

	
	if (key_name == NULL || prog_data->env == NULL)
		return (0);

	
	key_len = str_length(key_name);

	for (i = 0; prog_data->env[i]; i++)
	{
		if (str_compare(key_name, prog_data->env[i], key_len) &&
		 prog_data->env[i][key_len] == '=')
		{
			free(prog_data->env[i]);

			
			i++;
			for (; prog_data->env[i]; i++)
			{
				prog_data->env[i - 1] = prog_data->env[i];
			}
			
			prog_data->env[i - 1] = NULL;
			return (1);
		}
	}
	return (0);
}


/**
 * display_environ - function that prints the current environ
 * @prog_data: the program's data structure
 * Return: nothing
 */
void display_environ(data_of_program *prog_data)
{
	int j;

	for (j = 0; prog_data->env[j]; j++)
	{
		_print(prog_data->env[j]);
		_print("\n");
	}
}
