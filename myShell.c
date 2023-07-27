#include "main.h"

#define MAX_PATHS 50

extern char **environ;
/**
 * get_path - Get PATH from environment variable
 * @env: Pointer to the environment variables
 * @paths: Array to hold paths
 *
 * Return: The number of paths found in the PATH variable
 */
int get_path(char **env, char *paths[])
{
	int i;
	int path_index = 0;
	char *path_env = NULL;
	char *token;

	/* Get PATH from environ var */
	for (i = 0; env[i] != NULL; i++)
	{
		if (_strncmp(env[i], "PATH=", 5) == 0)
		{
			path_env = env[i] + 5;
			break;
		}
	}

	/* Break PATH into directories */
	token = strtok(path_env, ":");
	path_index = 0;

	while (token != NULL && path_index < MAX_PATHS)
	{
		paths[path_index++] = token;
		token = strtok(NULL, ":");
	}

	return (path_index);
}

/**
 * check_path - checks for PATH in input
 * @command_path: command
 * @paths: holds paths
 * @args: hold for tokens
 * @path_index: index count for path
 * @cmd_found: check for commands found in PATH
 *
 * Return: number of cmd_found
 */
int check_path(char *command_path, char *paths[], char *args[],
		int path_index, int cmd_found)
{
	int i;

	if (args[0][0] != '/')
	{
		for (i = 0; i < path_index; i++)
		{
			/*Concatenate the command with the path*/
			_strcpy(command_path, paths[i]);
			_strcat(command_path, "/");
			_strcat(command_path, args[0]);

			if (access(command_path, X_OK) == 0)
			{
				cmd_found = 1;
				break;
			}
		}
	}
	else
	{
		cmd_found = 1;
		_strcpy(command_path, args[0]);
	}

	return (cmd_found);
}

/**
 * main - checks code
 *Return: 0 on success
 */
#include "main.h"

int main(void)
{
	char *input = NULL;
	size_t input_size = 0;
	char *args[MAX_LINE_LENGTH];
	char *paths[50];
	char command_path[100];
	int path_index = 0;
	int command_found;
	char **env = environ;

	path_index = get_path(env, paths);

	while (1)
	{
		command_found = 0;

		/* Write prompt */
		prompt(&input, &input_size);

		if (_strncmp(input, " ", 2) == 0)
			continue;

		/* Tokenize input into arguments */
		tokenize_str(input, args);

		/* Check cmd for PATH */
		command_found = check_path(command_path, paths,
				args, path_index, command_found);

		/* Create process to execute command if found */
		if (command_found)
			fork_call(args, command_path);

		else
			printf("RE: Command does not exist\n");

	}

	/* Free allocated memory for input */
	free(input);
	return (0);
}
