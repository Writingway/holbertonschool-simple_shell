# Simple Shell

---

## Summary

- [Description](#Description)
- [Allowed_Functions](#Allowed_Functions)
- [Compilation_command](#Compilation_command)
- [Requirements](#Requirements)
- [Examples_of_use](#Examples_of_use)
- [Man_Page](#Man_Page)
- [Features](#Features)
- [Built-in-Commands](#Built-in-Commands)
- [Memory_Management](#Memory_Management)
- [Flowchart](#Flowchart)
- [Other](#Other)
- [Technologies_Used](#Technologies_Used)
- [Authors](#Authors)

---

## Description

**Simple Shell** is a pedagogical implementation of a UNIX command interpreter written in the C language. The program reproduces the basic behavior of a classic shell: it displays a prompt, reads user input, interprets the command, creates a child process and executes the requested program.

The project allows for a concrete understanding of the internal functioning of a shell, notably process management, the use of `fork`, `execve`, `wait`, as well as the resolution of commands via the environment variable `PATH`.

Usage The shell works in two modes: Interactive and Non-Interactive.

---

## Allowed_Functions

* Style: Code must follow the Betty style guide.
* File Structure: The project is modularized to comply with the limit of 5 functions per file.

* List of allowed functions:

 * all functions from string.h
 * access (man 2 access)
 * chdir (man 2 chdir)
 * close (man 2 close)
 * closedir (man 3 closedir)
 * execve (man 2 execve)
 * exit (man 3 exit)
 * _exit (man 2 _exit)
 * fflush (man 3 fflush)
 * fork (man 2 fork)
 * free (man 3 free)
 * getcwd (man 3 getcwd)
 * getline (man 3 getline)
 * getpid (man 2 getpid)
 * isatty (man 3 isatty)
 * kill (man 2 kill)
 * malloc (man 3 malloc)
 * open (man 2 open)
 * opendir (man 3 opendir)
 * perror (man 3 perror)
 * printf (man 3 printf)
 * fprintf (man 3 fprintf)
 * vfprintf (man 3 vfprintf)
 * sprintf (man 3 sprintf)
 * putchar (man 3 putchar)
 * read (man 2 read)
 * readdir (man 3 readdir)
 * signal (man 2 signal)
 * stat (__xstat) (man 2 stat)
 * lstat (__lxstat) (man 2 lstat)
 * fstat (__fxstat) (man 2 fstat)
 * strtok (man 3 strtok)
 * wait (man 2 wait)
 * waitpid (man 2 waitpid)
 * wait3 (man 2 wait3)
 * wait4 (man 2 wait4)
 * write (man 2 write)
 
---

## Compilation_command

The project is compiled with **GCC** respecting the following constraints:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

---

## Requirements

* Operating system : **Ubuntu 20.04 LTS**
* Compiler : **GCC** (GNU Compiler Collection)
* Tools :

  * `git`
  * `make` (optionnel)
  * `valgrind`
* Code standard : **Betty style**

---

## Examples_of_use

### Interactive

```bash
$ ./hsh
($) ls
main.c shell.c exec.c
($) pwd
/home/user/simple_shell
($) exit
```

### Non-Interactive

```bash
echo "ls -l" | ./hsh
```

**STDOUT Output :**

```text
total 32
-rw-r--r-- 1 user user  2048 main.c
-rw-r--r-- 1 user user  4096 exec.c
```

---

## Man_Page

A manual page is provided with the project.

Command to display it:

```bash
man ./man_1_simple_shell
```

If necessary, add execution rights to the file.

---

## Features

* Execution of simple commands : `ls`, `pwd`, `env`.
* Commands with arguments : `ls -l`, `echo hello`.
* Invalid commands not found.
* Handle `Ctrl+D` (EOF) and `Ctrl+C` (SIGINT).
* Non-interactive mode via pipe.
* Built-ins: `exit`, `env`.

---

## Built-in-Commands

The shell supports the following built-in commands that are executed directly by the shell process:

| Command | Description |
| --- | --- |
| **exit** | Exit the shell |
| **env** | Print the current environment |

---

## Memory_Management

All functions are rigorously tested for memory leaks and errors using Valgrind.
* Memory leak check :

```bash
valgrind --leak-check=full --show-leak-kinds=all ./hsh
```

* Results: No leaks detected, all allocated memory freed.
* Checks Performed :

```bash
==33785== HEAP SUMMARY:
==33785==     in use at exit: 0 bytes in 0 blocks
==33785==   total heap usage: 59 allocs, 59 frees, 10,027 bytes allocated
==33785== 
==33785== All heap blocks were freed -- no leaks are possible
==33785== 
==33785== For lists of detected and suppressed errors, rerun with: -s
==33785== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

---

## Flowchart

The overall functioning of the shell follows the following steps:

1. Prompt display
2. Reading user input
3. Parsing command
4. Research in the `PATH`
5. Creation of a process (`fork`)
6. Execution (`execve`)
7. Waiting for the child process (`wait`)
8. Prompt return

<img width="4520" height="11631" alt="image" src="https://github.com/user-attachments/assets/20f44f2a-5fac-45ec-9344-881ed7446ca7" />


---

## Other

* The shell manages environment variables.
* Errors are displayed on standard error output.
* The project strictly respects the Holberton constraints.
* Compatible with interactive and non-interactive execution.

---

## Technologies_Used

<div align="left">
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/c/c-original.svg" height="40" alt="c logo"  />
  <img width="12" />
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/github/github-original.svg" height="40" alt="github logo"  />
  <img width="12" />
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/linux/linux-original.svg" height="40" alt="linux logo"  />
  <img width="12" />
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/windows8/windows8-original.svg" height="40" alt="windows8 logo"  />
  <img width="12" />
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/vscode/vscode-original.svg" height="40" alt="vscode logo"  />
</div>

---

## Authors

* Mario Colomas – GitHub: @writingway
* Lucas Nevano – GitHub: @LunasN-ux
