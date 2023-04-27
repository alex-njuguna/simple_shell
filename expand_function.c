#include "main.h"

/**
 * expand_vars - function that expands the variables
 * @prog_data: a pointer to the program's data structure
 *
 * Return: nothing, but sets errno
 */

void expand_vars(data_of_program *prog_data)
{
	int i, j;
	char line[BUFFER_SIZE] = {0}, expansion[BUFFER_SIZE] = {'\0'}, *temp;

	if (prog_data->input_line == NULL)
		return;
	buffer_add(line, prog_data->input_line);
	for (i = 0; line[i]; i++)
		if (line[i] == '#')
			line[i--] = '\0';
		else if (line[i] == '$' && line[i + 1] == '?')
		{
			line[i] = '\0';
			long_to_string(errno, expansion, 10);
			buffer_add(line, expansion);
			buffer_add(line, prog_data->input_line + i + 2);
		}
		else if (line[i] == '$' && line[i + 1] == '$')
		{
			line[i] = '\0';
			long_to_string(getpid(), expansion, 10);
			buffer_add(line, expansion);
			buffer_add(line, prog_data->input_line + i + 2);
		}
		else if (line[i] == '$' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
			continue;
		else if (line[i] == '$')
		{
			for (j = 1; line[i + j] && line[i + j] != ' '; j++)
				expansion[j - 1] = line[i + j];
			temp = env_get_key(expansion, prog_data);
			line[i] = '\0', expansion[0] = '\0';
			buffer_add(expansion, line + i + j);
			temp ? buffer_add(line, temp) : 1;
			buffer_add(line, expansion);
		}
	if (!str_compare(prog_data->input_line, line, 0))
	{
		free(prog_data->input_line);
		prog_data->input_line = str_duplicate(line);
	}
}

/**
 * alias_expand - function to expand aliases
 * @prog_data: a pointer to the program's data structure
 *
 * Return: nothing, but set errno
 */

void alias_expand(data_of_program *prog_data)
{
	int i, j, new_expanded = 0;
	char line[BUFFER_SIZE] = {0}, expansion[BUFFER_SIZE] = {'\0'}, *temp;

	if (prog_data->input_line == NULL)
		return;

	buffer_add(line, prog_data->input_line);

	for (i = 0; line[i]; i++)
	{
		for (j = 0; line[i + j] && line[i + j] != ' '; j++)
			expansion[j] = line[i + j];
		expansion[j] = '\0';

		temp = show_alias(prog_data, expansion);
		if (temp)
		{
			expansion[0] = '\0';
			buffer_add(expansion, line + i + j);
			line[i] = '\0';
			buffer_add(line, temp);
			line[str_length(line)] = '\0';
			buffer_add(line, expansion);
			new_expanded = 1;
		}
		break;
	}
	if (new_expanded)
	{
		free(prog_data->input_line);
		prog_data->input_line = str_duplicate(line);
	}
}

/**
 * add_buffer - function to append string at end buffer
 * @buffer: the buffer to be added string
 * @string_add: the string to be added in the buffer
 * Return: nothing, but sets errno
 */
int add_buffer(char *buffer, char *string_add)
{
	int len, i;

	len = str_len(buffer);
	for (i = 0; string_add[i]; i++)
	{
		buffer[len + i] = string_add[i];
	}
	buffer[len + i] = '\0';
	return (len + i);
}
