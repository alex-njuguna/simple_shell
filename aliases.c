#include "main.h"

/**
 * display_alias - function to handle aliases
 * @data: program's data
 * @alias: name of the alias to be printed
 * Return: 0
 */
int display_alias(data_of_program *data, char *alias)
{
	int i, j, alias_length;
	char buffer[250] = {'\0'};

	if (data->alias_list)
	{
		alias_length = str_len(alias);
		for (i = 0; data->alias_list[i]; i++)
		{
			if (!alias || (str_compare(data->alias_list[i], alias, alias_length)
				&&	data->alias_list[i][alias_length] == '='))
			{
				for (j = 0; data->alias_list[i][j]; j++)
				{
					buffer[j] = data->alias_list[i][j];
					if (data->alias_list[i][j] == '=')
						break;
				}
				buffer[j + 1] = '\0';
				append_str(buffer, "'");
				append_str(buffer, data->alias_list[i] + j + 1);
				append_str(buffer, "'\n");
				_print(buffer);
			}
		}
	}

	return (0);
}

/**
 * retrieve_alias - handle aliases
 * @data: struct for the program's data
 * @name: name of the requested alias.
 * Return: 0
 */
char *retrieve_alias(data_of_program *data, char *name)
{
	int i, alias_length;

	if (name == NULL || data->alias_list == NULL)
		return (NULL);

	alias_length = str_len(name);

	for (i = 0; data->alias_list[i]; i++)
	{
		if (str_compare(name, data->alias_list[i], alias_length) &&
			data->alias_list[i][alias_length] == '=')
		{
			return (data->alias_list[i] + alias_length + 1);
		}
	}
	return (NULL);

}

/**
 * put_alias - implement alias
 * @alias_string: value
 * @data: struct for the program's data
 * Return: 0
 */
int put_alias(char *alias_string, data_of_program *data)
{
	int i, j;
	char buffer[250] = {'0'}, *temp = NULL;

	if (alias_string == NULL ||  data->alias_list == NULL)
		return (1);
	for (i = 0; alias_string[i]; i++)
		if (alias_string[i] != '=')
			buffer[i] = alias_string[i];
		else
		{
			temp = retrieve_alias(data, alias_string + i + 1);
			break;
		}

	for (j = 0; data->alias_list[j]; j++)
		if (str_compare(buffer, data->alias_list[j], i) &&
			data->alias_list[j][i] == '=')
		{
			free(data->alias_list[j]);
			break;
		}

	if (temp)
	{
		append_str(buffer, "=");
		append_str(buffer, temp);
		data->alias_list[j] = str_dup(buffer);
	}
	else
		data->alias_list[j] = str_dup(alias_string);
	return (0);
}
