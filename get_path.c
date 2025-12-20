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
	retrurn (NULL);
 }
