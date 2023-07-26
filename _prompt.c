#include "main.h"

/**
 * prompt - Prompts and reads input from the user
 * @input: Pointer to the input read
 * @n: Size of the input
 *
 * Return: Nothing
 */
void prompt(char **input, size_t *n)
{
    size_t input_length;
    ssize_t line_sum;

    /* Write prompt */
    write(STDOUT_FILENO, "$ ", 2);

    line_sum = getline(input, n, stdin);

    if (line_sum == -1)
    {
        write(STDOUT_FILENO, "\n", 1);
        exit(EXIT_SUCCESS);
    }

    /* Removes "\n" char from input and null terminate it */
    input_length = _strcspn(*input, "\n");
    (*input)[input_length] = '\0';

    if (_strcmp(*input, "exit") == 0)
    {
        exit(EXIT_SUCCESS);
    }
}
