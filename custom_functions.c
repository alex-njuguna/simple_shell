#include "main.h"

/**
* mystrcmp - compare two strings
* @str1: first argument
* @str2: second arg
* Return: difference between the two strings
*/

int mystrcmp(const char *str1, const char *str2)
{
	int i = 0;

	while (str1[i] == str2[i])
	{
		if (str1[i] == '\0')
		return (0);
		i++;
	}
	return (str1[i] - str2[i]);
}

/**
* mystrcspn - check str in another str
* @str1: arg 1
* @str2: arg 2
* Return: count
*/

size_t mystrcspn(const char *str1, const char *str2)
{
	const char *p;
	const char *q;
size_t count = 0;

	for (p = str1; *p != '\0'; p++)
	{
		for (q = str2; *q != '\0'; q++)
		{
			if (*p == *q)
			{
			return (count);
			}
		}
		count++;
	}

	return (count);
}

/**
* myprintf - print output
* @format: input format
* @...: other par
*/

void myprintf(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}

/**
* myputchar - prints a character
* @c: test par
* Return: a integer
*/

int myputchar(char c)
{
	return (write(1, &c, 1));
}
