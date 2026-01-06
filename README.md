# Simple Shell

---

## Summary

[Description](#Description)
[Compilation](#Compilation_command)
[Built-in-Commands](#Built-in-Commands)
[Compilation_command](#Compilation_command)
[Requirements](#Requirements)
[Examples_of_use](#Examples_of_use)
[Man_Page](#Man_Page)
[Testing](#Testing)
[Flowchart](#Flowchart)
[Other](#Other)
[Technologies_Used](#Technologies_Used)
[Authors](#Authors)


---

## Description

**Simple Shell** is a pedagogical implementation of a UNIX command interpreter written in the C language. The program reproduces the basic behavior of a classic shell: it displays a prompt, reads user input, interprets the command, creates a child process and executes the requested program.

The project allows for a concrete understanding of the internal functioning of a shell, notably process management, the use of `fork`, `execve`, `wait`, as well as the resolution of commands via the environment variable `PATH`.

Usage The shell works in two modes: Interactive and Non-Interactive.

---

## Built-in-Commands

The shell supports the following built-in commands that are executed directly by the shell process:

|Command|Description|
|exit|Exit the shell|
|env|Print the current environment|

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

## Testing

### Tests manuels

* Execution of simple commands : `ls`, `pwd`, `env`
* Commands with arguments : `ls -l`, `echo hello`
* Invalid orders
* Manage of `EOF` (Ctrl + D)
* Non-interactive mode via pipe

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

(Un flowchart visuel peut être ajouté dans le dossier `assets/`.)

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
