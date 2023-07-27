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
