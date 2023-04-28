#include "main.h"

/**
 * str_len - find len of str
 * @str: test par
 * Return: len
 */
int str_len(char *str)
{
	int length = 0;

	if (str == NULL)
		return (0);

	while (str[length++] != '\0')
	{
	}
	return (--length);
}

/**
 * str_dup - exact copy of a str
 * @str: test par
 * Return: pointer to the array
 */
char *str_dup(char *str)
{
	char *result;
	int length, i;

	if (str == NULL)
		return (NULL);

	length = str_len(str) + 1;

	result = malloc(sizeof(char) * length);

	if (result == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}
	for (i = 0; i < length ; i++)
	{
		result[i] = str[i];
	}

	return (result);
}

/**
 * str_compare - Compare two strings
 * @str1: par 1
 * @str2: par 2
 * @number: par 3
 * Return: 1 or 0
 */
int str_compare(char *str1, char *str2, int number)
{
	int iterator;

	if (str1 == NULL && str2 == NULL)
		return (1);

	if (str1 == NULL || str2 == NULL)
		return (0);

	if (number == 0)
	{
		if (str_len(str1) != str_len(str2))
			return (0);
		for (iterator = 0; str1[iterator]; iterator++)
		{
			if (str1[iterator] != str2[iterator])
				return (0);
		}
		return (1);
	}
	else
	{
		for (iterator = 0; iterator < number ; iterator++)
		{
			if (str1[iterator] != str2[iterator])
			return (0);
		}
		return (1);
	}
}

/**
 * str_join - join 2 str
 * @str1: par 1
 * @str2: par 2
 * Return: pointer to the string
 */
char *str_join(char *str1, char *str2)
{
	char *result;
	int length1 = 0, length2 = 0;

	if (str1 == NULL)
		str1 = "";
	length1 = str_len(str1);

	if (str2 == NULL)
		str2 = "";
	length2 = str_len(str2);

	result = malloc(sizeof(char) * (length1 + length2 + 1));
	if (result == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}

	for (length1 = 0; str1[length1] != '\0'; length1++)
		result[length1] = str1[length1];
	free(str1);

	for (length2 = 0; str2[length2] != '\0'; length2++)
	{
		result[length1] = str2[length2];
		length1++;
	}

	result[length1] = '\0';
	return (result);
}


/**
 * str_rev - reverses a string
 * @str: test par
 */
void str_rev(char *str)
{

	int i = 0, length = str_len(str) - 1;
	char hold;

	while (i < length)
	{
		hold = str[i];
		str[i++] = str[length];
		str[length--] = hold;
	}
}
