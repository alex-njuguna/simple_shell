#include "main.h"

/**
 * free_data - function to free recurrent data
 * @prog_data: the program's data structure
 * Return: Nothing
 */

void free_data(data_of_program *prog_data)
{
	if (prog_data->tokens)
		free_pointers_array(prog_data->tokens);
	if (prog_data->input_line)
		free(prog_data->input_line);
	if (prog_data->command_name)
		free(prog_data->command_name);

	prog_data->input_line = NULL;
	prog_data->command_name = NULL;
	prog_data->tokens = NULL;
}

/**
 * free_data_all - function to free all data
 * @prog_data: the program's data structure
 * Return: Nothing
 */

void free_data_all(data_of_program *prog_data)
{
	if (prog_data->file_descriptor != 0)
	{
		if (close(prog_data->file_descriptor))
			perror(prog_data->program_name);
	}
	free_data(prog_data);
	free_pointers_array(prog_data->env);
	free_pointers_array(prog_data->alias_list);
}

/**
 * free_pointers_array - funtion to free pointers of an array of pointers and the
 * array also
 * @pointers_array: the array of pointers
 * Return: nothing
 */

void free_pointers_array(char **pointers_array)
{
	int i;

	if (pointers_array != NULL)
	{
		for (i = 0; pointers_array[i]; i++)
			free(pointers_array[i]);

		free(pointers_array);
		pointers_array = NULL;
	}
}
