#include "main.h"

/**
 * find_path - Cherche le chemin complet d'une commande
 * @cmd: commande entrée
 * @env: variables d'environnement
 * Return: chemin complet de la commande si trouvée, NULL sinon
 */
char *find_path(char *cmd, char **env)
{
	char *path_env = NULL, *copy, *dir, *full;
	int i;

	if (!cmd)
		return (NULL);
	if (strchr(cmd, '/')) /* absolute or relative path */
		return (access(cmd, X_OK) == 0 ? strdup(cmd) : NULL);
	/* Research PATH into environment variables */
	for (i = 0; env[i]; i++)
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
		{
			path_env = env[i] + 5;
			break;
		}
	}
	if (!path_env)
		return (NULL);
	copy = strdup(path_env);
	if (!copy)
		return (NULL);
	dir = strtok(copy, ":");
	while (dir)
	{
		full = malloc(strlen(dir) + strlen(cmd) + 2);
		if (!full)
			break;
		sprintf(full, "%s/%s", dir, cmd);
		if (access(full, X_OK) == 0)
		{
			free(copy);
			return (full);
		}
		free(full);
		dir = strtok(NULL, ":");
	}
	free(copy);
	return (NULL);
}
