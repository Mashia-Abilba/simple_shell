A team project by Mashia Abilba and Uchenna Chinazaekpere 

NAME OF PROJECT: SIMPLE SHELL

GITHUB REPO: simple_shell

This project contains 6 tasks on the basic commands of the shell and how it executes these commands to produce output for the user.

0- betty would be proud
Write a beautiful code that passes the Betty checks

1-simple shell 0.1
Write a UNIX command line interpreter.

Usage: simple_shell
Your Shell should:

Display a prompt and wait for the user to type a command. A command line always ends with a new line.
The prompt is displayed again each time a command has been executed.
The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
The command lines are made only of one word. No arguments will be passed to programs.
If an executable cannot be found, print an error message and display the prompt again.
Handle errors.
You have to handle the “end of file” condition (Ctrl+D)
You don’t have to:

use the PATH
implement built-ins
handle special characters : ", ', `, \, *, &, #
be able to move the cursor
handle commands with arguments
execve will be the core part of your Shell, don’t forget to pass the environ to it…

2- simple shell 0.2
Simple shell 0.1 +

Handle command lines with arguments

3- simple shell 0.3
Simple shell 0.2 +

Handle the PATH
fork must not be called if the command doesn’t exist

4- simple shell 0.4
Simple shell 0.3 +

Implement the exit built-in, that exits the shell
Usage: exit
You don’t have to handle any argument to the built-in exit

5- simple shell 1.0
Simple shell 0.4 +

Implement the env built-in, that prints the current environment
