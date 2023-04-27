#include "main.h"

/**
 * display_alias - function that adds, remove and display aliases
 * @prog_data: the structure for the program's contents
 * @alias_name: the name of the alias to be displayed
 * Return: 0 on sucess, or other as declared in the arguments
 */
int display_alias(data_of_program *prog_data, char *alias_name)
{
	int i, j, alias_len;
	char buffer[250] = {'\0'};

	if (prog_data->alias_list)
	{
		alias_len = str_length(alias);
		for (i = 0; prog_data->alias_list[i]; i++)
		{
			if (!alias_name || (str_compare(prog_data->alias_list[i], alias_name, alias_len)
				&&	prog_data->alias_list[i][alias_len] == '='))
			{
				for (j = 0; prog_data->alias_list[i][j]; j++)
				{
					buffer[j] = prog_data->alias_list[i][j];
					if (prog_data->alias_list[i][j] == '=')
						break;
				}
				buffer[j + 1] = '\0';
				buffer_add(buffer, "'");
				buffer_add(buffer, prog_data->alias_list[i] + j + 1);
				buffer_add(buffer, "'\n");
				_print(buffer);
			}
		}
	}

	return (0);
}

/**
 * show_alias - function that adds, remove or display aliases
 * @prog_data: the program's data structure
 * @name_alias: the name of the alias
 * Return: 0 on sucess, or other declared in the arguments
 */
char *show_alias(data_of_program *prog_data, char *name_alias)
{
	int i, alias_len;

	
	if (name_alias == NULL || prog_data->alias_list == NULL)
		return (NULL);

	alias_len = str_length(name_alias);

	for (i = 0; prog_data->alias_list[i]; i++)
	{
		if (str_compare(name_alias, prog_data->alias_list[i], alias_len) &&
			prog_data->alias_list[i][alias_len] == '=')
		{
			return (prog_data->alias_list[i] + alias_len + 1);
		}
	}

	return (NULL);

}

/**
 * add_alias - function to add, or override alias
 * @alias_str: the alias tobe displayed the form (name='value')
 * @prog_data: the program's data structure
 * Return: 0 on sucess, or other as declared in the arguments
 */
int add_alias(char *alias_str, data_of_program *prog_data)
{
	int i, j;
	char buffer[250] = {'0'}, *temp = NULL;

	
	if (alias_str == NULL ||  prog_data->alias_list == NULL)
		return (1);
	
	for (i = 0; alias_str[i]; i++)
		if (alias_str[i] != '=')
			buffer[i] = alias_str[i];
		else
		{
			temp = add_alias(prog_data, alias_str + i + 1);
			break;
		}

	
	for (j = 0; prog_data->alias_list[j]; j++)
		if (str_compare(buffer, prog_data->alias_list[j], i) &&
			prog_data->alias_list[j][i] == '=')
		{
			free(prog_data->alias_list[j]);
			break;
		}

	
	if (temp)
	{
		buffer_add(buffer, "=");
		buffer_add(buffer, temp);
		prog_data->alias_list[j] = str_duplicate(buffer);
	}
	else 
		prog_data->alias_list[j] = str_duplicate(alias_str);
	return (0);
}
