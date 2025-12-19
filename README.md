# Simple Shell

## Description du projet

**Simple Shell** est une implémentation pédagogique d’un interpréteur de commandes UNIX écrit en langage C. Le programme reproduit le comportement de base d’un shell classique : il affiche un prompt, lit l’entrée utilisateur, interprète la commande, crée un processus fils et exécute le programme demandé.

Le projet permet de comprendre concrètement le fonctionnement interne d’un shell, notamment la gestion des processus, l’utilisation de `fork`, `execve`, `wait`, ainsi que la résolution des commandes via la variable d’environnement `PATH`.

---

## Commande de compilation

Le projet est compilé avec **GCC** en respectant les contraintes suivantes :

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

---

## Requirements

* Système d’exploitation : **Ubuntu 20.04 LTS**
* Compilateur : **GCC** (GNU Compiler Collection)
* Outils :

  * `git`
  * `make` (optionnel)
  * `valgrind`
* Norme de code : **Betty style**

---

## Exemples d’utilisation

### Mode interactif

```bash
$ ./hsh
($) ls
main.c shell.c exec.c
($) pwd
/home/user/simple_shell
($) exit
```

### Mode non interactif

```bash
echo "ls -l" | ./hsh
```

**Sortie STDOUT :**

```text
total 32
-rw-r--r-- 1 user user  2048 main.c
-rw-r--r-- 1 user user  4096 exec.c
```

---

## Man Page

Une page de manuel est fournie avec le projet.

Commande pour l’afficher :

```bash
man ./man_1_simple_shell
```

Si nécessaire, ajouter les droits d’exécution au fichier.

---

## Testing

### Tests manuels

* Exécution de commandes simples : `ls`, `pwd`, `env`
* Commandes avec arguments : `ls -l`, `echo hello`
* Commandes invalides
* Gestion de `EOF` (Ctrl + D)
* Mode non interactif via pipe

### Valgrind

Vérification des fuites mémoire :

```bash
valgrind --leak-check=full --show-leak-kinds=all ./hsh
```

Aucune fuite mémoire ne doit être détectée.

---

## Flowchart

Le fonctionnement global du shell suit les étapes suivantes :

1. Affichage du prompt
2. Lecture de l’entrée utilisateur
3. Parsing de la commande
4. Recherche dans le `PATH`
5. Création d’un processus (`fork`)
6. Exécution (`execve`)
7. Attente du processus fils (`wait`)
8. Retour au prompt

(Un flowchart visuel peut être ajouté dans le dossier `assets/`.)

---

## Autres informations utiles

* Le shell gère les variables d’environnement
* Les erreurs sont affichées sur la sortie d’erreur standard
* Le projet respecte strictement les contraintes Holberton
* Compatible avec l’exécution interactive et non interactive

---

## Auteurs

* Mario Colomas – GitHub: @writingway
* Lucas Nevano – GitHub: @LunasN-ux
