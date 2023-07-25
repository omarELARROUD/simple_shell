#include "main.h"

void prompt(char **input, size_t *n)
{
	size_t input_length;
	ssize_t line_sum;	

        /*write prompt*/
	write(STDOUT_FILENO, ":) ", 3);

	line_sum = getline(input, n, stdin);

	if (line_sum == -1)
	{
		write(STDOUT_FILENO, "\n", 2);
		exit(EXIT_SUCCESS);
	}

	/*removes "\n" char from input and null terminate it */
	input_length = _strcspn(*input, "\n");
	(*input)[input_length] = '\0';

	if (_strcmp(*input, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
}
