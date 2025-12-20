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
	}
	return (NULL);
 }

/**
 * find_command - séquencer le PATH juqu'a trouvé le bon chemin
 * @cmd: commande entrée
 * @env: The environment variables
 * Return: 0
 */
char *find_command(char *cmd, char **env)
 {
	char *path_env;
	char *path_copy;
	char *dir;
	char *full_path;

	/* chemin absolu*/
	if (cmd[0] == '/' && access(cmd, X_OK) == 0) /* si le prompt est executable */
		return strdup(cmd); /*retourne direct le chemin */
	
	/* récuperer le PATH */
	path_env = get_path(env);
		if (!path_env)
			return (NULL);
	
	/* Copier le PATH */
	path_copy = strdup(path_env); /* on travail sur une copie */
	dir = strtok(path_copy, ":"); /* decouper sur : */

	/* parcourir les dossiers */
	while (dir)
	{
		full_path = malloc(strlen(dir + strlen(cmd) + 2)); /* 1 pour / et 1 pour \O */
		sprintf(full_path, "%s/%s", dir , cmd);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path); /* trouvé */
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL); /* commande introuvable */

 }
