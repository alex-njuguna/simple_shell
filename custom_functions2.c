#include "main.h"


/**
* execute_program - run a program
* @buffer: pointer to string buffer
* @argv: pointer to split commands
* @length: pointer to buffer length
* @envp: environment variables
* Return: 0 or 1
*/
int execute_program(char *buffer, char **argv, size_t *length, char **envp)
{
	int ret;
	char *ispath;

	if (mystrcmp(argv[0], "exit") == 0)
	{
		if (argv[1])
			exit(abs(atoi(argv[1])));
		else
			exit(0);
	}

	if (mystrcmp(argv[0], "setenv") == 0 || mystrcmp(argv[0], "unsetenv") == 0)
	{
		ret = mysetenv(argv);
		if (ret < 0)
			return (1);
	}
	ispath = findpath(argv[0]);
	if (ispath == NULL)
	{
		show_error("command not found\n", &buffer, length, argv);
		return (1);
	}

	ret = newproc(buffer, argv, length, envp, ispath);
	return (ret);
}

/**
* newproc - new process and run prog in thhe process
* @buffer: pointer to commands
* @argv: pointer to split commands
* @envp:environment variables
* @len: pointer to number of characters
* @path: pointer to path
* Return: 0 or 1
*/
int newproc(char *buffer, char **argv, size_t *len, char **envp, char *path)
{
	pid_t pid, execve_ret, st;

	pid = fork();
	if (pid < 0)
	{
		show_error("fork failed\n", &buffer, len, argv);
		return (1);
	}
	else if (pid == 0)
	{
		execve_ret = execve(path, argv, envp);
		if (execve_ret == -1)
		{
			show_error("execve failed\n", &buffer, len, argv);
			return (1);
		}
		pipe_in();
	}
	else
	{
		wait(&st);
	}

	return (0);
}

/**
* mysetenv - makes or removes env var
* @argv: pointer to spilt commands
* Return: 0 or -1
*/
int mysetenv(char **argv)
{
	int succ = 0, fderr = 2;

	if (mystrcmp(argv[0], "setenv") == 0)
	{
		if (strarr_count(argv) != 3)
		{
			succ = -1;
			myprintf(fderr, "Usage: setenv VARIABLE VALUE\n");
		}
		else
			argv[0] = "export";
	}
	else
	{
		if (strarr_count(argv) != 2)
		{
			succ = -1;
			myprintf(fderr, "unsetenv failed\n");
		}
		else
			argv[0] = "unset";
	}
	return (succ);
}

/**
* strarr_count - check elements in a str array
* @argv: string array
* Return: count
*/
int strarr_count(char **argv)
{
	int i = 0;

	if (argv)
	{
		while (argv[i] != NULL)
		{
			i++;
		}
	}

	return (i);
}

/**
* findpath - find path of cmd
* @cmd: test par
* Return: path found or NULL
*/
char *findpath(char *cmd)
{
	char *allpath = getenv("PATH");
	int i = 0;
	char *str, ch;

	if (cmd[0] == '/')
	{
		if (access(cmd, F_OK) == 0)
		{
			return (cmd);
		}
		return (NULL);
	}
	if (allpath)
	{
		while (*allpath != '\0')
		{
			ch = *allpath;
			if (i == 0)
				str = malloc(sizeof(char));

			if (ch != ':')
			{
				str = realloc(str, (i + 1) * sizeof(char));
				str[i] = ch;
				i++;
			}
			else
			{
				str = realloc(str, ((i + 1) + string_length(cmd) + 2) * sizeof(char));
				str = combine_strings(str, cmd, '/');

				if (access(str, F_OK) == 0)
					return (str);
				memset(str, '\0', i);
				i = 0;
			}
			allpath += 1;
		}
	}
	return (NULL);
}
