#include "main.h"
/**
 * _strtok - split str
 * @line: command
 * @delimator: marker
 * Return: result
*/
char *_strtok(char *line, char *delimator)
{
	int j;
	static char *str;
	char *copystr;

	if (line != NULL)
		str = line;
	for (; *str != '\0'; str++)
	{
		for (j = 0; delimator[j] != '\0'; j++)
		{
			if (*str == delimator[j])
			break;
		}
		if (delimator[j] == '\0')
			break;
	}
	copystr = str;
	if (*copystr == '\0')
		return (NULL);
	for (; *str != '\0'; str++)
	{
		for (j = 0; delimator[j] != '\0'; j++)
		{
			if (*str == delimator[j])
			{
				*str = '\0';
				str++;
				return (copystr);
			}
		}
	}
	return (copystr);
}
