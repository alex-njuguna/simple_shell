#include "main.h"

/**
  * myprintf - output a string
  * @fd: file decripto
  * @str: test par
  */
void myprintf(int fd, char *str)
{
	write(fd, str, (string_length(str) * sizeof(char)));
}

/**
  * string_length - check no of characters
  * @str: test par
  * Return: no of chars
  */
int string_length(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
  * mystrcmp - compares two strings
  * @str1: test par 1
  * @str2: test par 2
  * Return: 0
  */
int mystrcmp(char *str1, char *str2)
{
	int i = 0;

	while (str1[i] != '\0')
	{
		if (str2[i] == '\0')
			break;
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

/**
  * combine_strings - combines strings with a given symbol
  * @st1: test par1
  * @st2: test par2
  * @c: symbol
  * Return: pointe to combined string
  */
char *combine_strings(char *st1, char *st2, char c)
{
	char *newStr;
	int i = 0;

	newStr = malloc((string_length(st1) + string_length(st2) + 2) * sizeof(char));

	while (*st1 != '\0')
	{
		newStr[i] = *st1;
		st1 += 1;
		i++;
	}

	newStr[i] = c;
	i++;

	while (*st2 != '\0')
	{
		newStr[i] = *st2;
		st2 += 1;
		i++;
	}

	newStr[i] = '\0';
	return (newStr);
}
/**
  * show_error - show error
  * @msg: message to show
  * @buffer: pointer to buffer pointer
  * @length: pointer to size of chars
  * @argv: pointer to commands
  */
void show_error(char *msg, char **buffer, size_t *length, char **argv)
{
	int fderr = 2;
	char *err;

	err = combine_strings(argv[0], msg, ':');
	write(fderr, err, string_length(err) * sizeof(char));
	*buffer = NULL;
	*length = 0;
}
