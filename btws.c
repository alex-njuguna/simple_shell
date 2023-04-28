#include "main.h"

/**
 * expand_variables - ..
 * @data: pointer to the program's data
 */
void expand_variables(data_of_program *data)
{
	int i, j;
	char line[BUFFER_SIZE] = {0}, expansion[BUFFER_SIZE] = {'\0'}, *temp;

	if (data->input_line == NULL)
		return;
	append_str(line, data->input_line);
	for (i = 0; line[i]; i++)
		if (line[i] == '#')
			line[i--] = '\0';
		else if (line[i] == '$' && line[i + 1] == '?')
		{
			line[i] = '\0';
			num_to_str(errno, expansion, 10);
			append_str(line, expansion);
			append_str(line, data->input_line + i + 2);
		}
		else if (line[i] == '$' && line[i + 1] == '$')
		{
			line[i] = '\0';
			num_to_str(getpid(), expansion, 10);
			append_str(line, expansion);
			append_str(line, data->input_line + i + 2);
		}
		else if (line[i] == '$' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
			continue;
		else if (line[i] == '$')
		{
			for (j = 1; line[i + j] && line[i + j] != ' '; j++)
				expansion[j - 1] = line[i + j];
			temp = get_env_var(expansion, data);
			line[i] = '\0', expansion[0] = '\0';
			append_str(expansion, line + i + j);
			temp ? append_str(line, temp) : 1;
			append_str(line, expansion);
		}
	if (!str_compare(data->input_line, line, 0))
	{
		free(data->input_line);
		data->input_line = str_dup(line);
	}
}

/**
 * more_alias - ..
 * @data: program's data
 */
void more_alias(data_of_program *data)
{
	int i, j, was_expanded = 0;
	char line[BUFFER_SIZE] = {0}, expansion[BUFFER_SIZE] = {'\0'}, *temp;

	if (data->input_line == NULL)
		return;

	append_str(line, data->input_line);

	for (i = 0; line[i]; i++)
	{
		for (j = 0; line[i + j] && line[i + j] != ' '; j++)
			expansion[j] = line[i + j];
		expansion[j] = '\0';

		temp = retrieve_alias(data, expansion);
		if (temp)
		{
			expansion[0] = '\0';
			append_str(expansion, line + i + j);
			line[i] = '\0';
			append_str(line, temp);
			line[str_len(line)] = '\0';
			append_str(line, expansion);
			was_expanded = 1;
		}
		break;
	}
	if (was_expanded)
	{
		free(data->input_line);
		data->input_line = str_dup(line);
	}
}

/**
 * append_str - append string at end of the buffer
 * @buffer: buffer
 * @str: value
 * Return: 0
 */
int append_str(char *buffer, char *str)
{
	int length, i;

	length = str_len(buffer);
	for (i = 0; str[i]; i++)
	{
		buffer[length + i] = str[i];
	}
	buffer[length + i] = '\0';
	return (length + i);
}
