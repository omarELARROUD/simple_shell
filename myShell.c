#include "main.h"

#define MAX_LINE_LENGTH 1024

extern char **environ;

int main()
{
    char *input = NULL;
    size_t input_size = 0;
    char *args[MAX_LINE_LENGTH];
	char *paths[50];
	char *path_env = NULL, *token;
	char command_path[100];
	int command_found, path_index, i;

	/*get PATH from environ var*/
	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], "PATH=", 5) == 0)
		{
			path_env = environ[i] + 5;
			break;
		}
	}

	/*break PATH into dir*/
	token = strtok(path_env, ":");
	path_index = 0;

	while (token != NULL && path_index < 50)
	{
        	paths[path_index++] = token;
        	token = strtok(NULL, ":");
	}


    while (1)
    {
	command_found = 0;

        /*write prompt*/
	prompt(&input, &input_size);

	if (_strncmp(input, " ", 2) == 0)
		continue;

        /*TOKENIZE input into arguments*/
        tokenize_str(input, args);
	
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
                    		command_found = 1;
                    		break;
			}
		}
	}
	else
	{
		command_found = 1;
		_strcpy(command_path, args[0]);
	}

        /*create process to execute command if found*/
	if (command_found)
		fork_call(args, command_path);
	else
		printf("RE: Command does not exist\n");
    }

    /* Free allocated memory for input */
    free(input);

    return (0);
}
