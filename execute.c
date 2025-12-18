#include "main.h"

/**
 * execute_command - Executes a command
 * @line: The command line to execute
 * @env: The environment variables
 */
void execute_command(char *line, char **env)
{
	char *argv[2];
	pid_t pid;
	int status;

	/* ligne vide on return au debut de la boucle */
	if (!line || *line == '\0')
		return;

	/* préparer les arguments pour execve */
	argv[0] = line;
	argv[1] = NULL;

	/* créer un nouveau processus */
	pid = fork();
	if (pid == -1)
	{
		/* erreur lors de la création du processus */
		perror("fork failed");
		return;
	}

	if (pid == 0) /* fils */
	{
		/* exécuter la commande */
		if (execve(argv[0], argv, env) == -1)
		{
			fprintf(stderr, "shell: %s: command not found\n", argv[0]);
			/*printf("argv[0] %s argv %s env %s\n", argv[0], *argv, *env);*/
		}
		exit(127);
	}
	else /* père*/
	{
		waitpid(pid, &status, 0);
	}
}
