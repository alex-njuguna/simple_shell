#include "main.h"

/**
 * locate_program - ..
 * @data: the program's data
 * Return: 0
 */
int locate_program(data_of_program *data)
{
	int i = 0, ret_code = 0;
	char **directories;

	if (!data->command_name)
		return (2);

	if (data->command_name[0] == '/' || data->command_name[0] == '.')
		return (ascertain_file(data->command_name));

	free(data->tokens[0]);
	data->tokens[0] = str_join(str_dup("/"), data->command_name);
	if (!data->tokens[0])
		return (2);

	directories = split_path(data);

	if (!directories || !directories[0])
	{
		errno = 127;
		return (127);
	}
	for (i = 0; directories[i]; i++)
	{
		directories[i] = str_join(directories[i], data->tokens[0]);
		ret_code = ascertain_file(directories[i]);
		if (ret_code == 0 || ret_code == 126)
		{
			errno = 0;
			free(data->tokens[0]);
			data->tokens[0] = str_dup(directories[i]);
			free_pointers_array(directories);
			return (ret_code);
		}
	}
	free(data->tokens[0]);
	data->tokens[0] = NULL;
	free_pointers_array(directories);
	return (ret_code);
}

/**
 * split_path - split the path in directories
 * @data: program's data
 * Return: directories
 */
char **split_path(data_of_program *data)
{
	int i = 0;
	int counter_directories = 2;
	char **tokens = NULL;
	char *PATH;

	PATH = get_env_var("PATH", data);
	if ((PATH == NULL) || PATH[0] == '\0')
	{
		return (NULL);
	}

	PATH = str_dup(PATH);

	for (i = 0; PATH[i]; i++)
	{
		if (PATH[i] == ':')
			counter_directories++;
	}

	tokens = malloc(sizeof(char *) * counter_directories);

	i = 0;
	tokens[i] = str_dup(_strtok(PATH, ":"));
	while (tokens[i++])
	{
		tokens[i] = str_dup(_strtok(NULL, ":"));
	}

	free(PATH);
	PATH = NULL;
	return (tokens);

}

/**
 * ascertain_file - check file
 * @file_path: file path
 * Return: 0
 */
int ascertain_file(char *file_path)
{
	struct stat sb;

	if (stat(file_path, &sb) != -1)
	{
		if (S_ISDIR(sb.st_mode) ||  access(file_path, X_OK))
		{
			errno = 126;
			return (126);
		}
		return (0);
	}
	errno = 127;
	return (127);
}
