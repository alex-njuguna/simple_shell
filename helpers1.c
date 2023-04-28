#include "main.h"

/**
 * free_recurrent_data - keep the buffers clean
 * @data: ..
 */
void free_recurrent_data(data_of_program *data)
{
	if (data->tokens)
		free_pointers_array(data->tokens);
	if (data->input_line)
		free(data->input_line);
	if (data->command_name)
		free(data->command_name);

	data->input_line = NULL;
	data->command_name = NULL;
	data->tokens = NULL;
}

/**
 * free_data - clean all data
 * @data: ..
 */
void free_data(data_of_program *data)
{
	if (data->file_descriptor != 0)
	{
		if (close(data->file_descriptor))
			perror(data->program_name);
	}
	free_recurrent_data(data);
	free_pointers_array(data->env);
	free_pointers_array(data->alias_list);
}

/**
 * free_pointers_array - ..
 * @myarray: array of pointers
 */
void free_pointers_array(char **myarray)
{
	int i;

	if (myarray != NULL)
	{
		for (i = 0; myarray[i]; i++)
			free(myarray[i]);

		free(myarray);
		myarray = NULL;
	}
}
