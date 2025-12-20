#include "main.h"

/**
 * get_path - récuperer la valeur du PATH depuis envp
 * @env: The environment variables
 * Return: variables after PATH=
 */

char *get_path(char **env)
{
	int i = 0;

	while (env[i]) /* Parcourt les variables */
	{
		if (strncmp(env[i], "PATH=", 5) == 0) /* Si variable commence par PATH= */
			return (env[i] + 5); /* retourne tout ce qui est après PATH= */
		i++;
	}
	return (NULL);
}


/**
 * find_path - Cherche le chemin complet d'une commande
 * @cmd: commande entrée
 * @env: variables d'environnement
 * Return: chemin complet de la commande si trouvée, NULL sinon
 */
char *find_path(char *cmd, char **env)
{
	char *path_env;
	char *path_copy;
	char *dir;
	char *full_path;

	if (cmd == NULL || strlen(cmd) == 0)
		return (NULL);
	/* Si cmd contient un '/' -> chemin relatif ou absolu */
	if (strchr(cmd, '/') != NULL)
	{
		if (access(cmd, X_OK) == 0)
			return (strdup(cmd));
		return (NULL);
	}
	/* Récupérer PATH */
	path_env = get_path(env);
	if (path_env == NULL)
		return (NULL);
	path_copy = strdup(path_env);
	if (path_copy == NULL)
		return (NULL);
	dir = strtok(path_copy, ":");
	while (dir)
	{
		/* Allouer assez de mémoire pour dir + '/' + cmd + '\0' */
		full_path = malloc(strlen(dir) + strlen(cmd) + 3);
		if (full_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}
		sprintf(full_path, "%s/%s", dir, cmd);
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
