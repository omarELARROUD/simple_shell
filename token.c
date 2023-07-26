#include "main.h"

/**
 * tokenize_str - break up string into tokens
 * @str: string arg
 * @args: hold for tokens
 * Return: nothing
 */
void tokenize_str(char *str, char *args[])
{
	int i = 0;
	char *token;

	/*Checks if the first char in str is '/'*/
	if (str[0] == '/')
	{
		args[i++] = str;
		args[i] = NULL;
	}
	else
	{
		token = strtok(str, " \t\n");
		while (token)
		{
			args[i] = token;
			token = strtok(NULL, " \t\n");
			i++;
		}
		args[i] = NULL;
	}
}

