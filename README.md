![image](https://github.com/hug0-cstrs/holbertonschool-monty/assets/124585936/84c7ae82-e546-4fab-9576-5482bd422cb5)
---
## Title:

# Monty bytecode interpreter
---
## Project :

# C - Stacks, Queues - LIFO, FIFO
---
## Description :

Monty is a simple interpreter for the Monty bytecode language. It reads Monty files of bytecode instructions and interprets them. Monty files have the ".m" extension and contain one instruction per line. There is also an interactive mode for testing purposes.

Supported Instructions
Instruction	Description
push	Pushes an element to the stack
pall	Prints all the elements of the stack
pint	Prints the value at the top of the stack
pop	Removes the top element of the stack
swap	Swaps the top two elements of the stack
add	Adds the top two elements of the stack
sub	Subtracts the top element of the stack from the second
new_Node()	Creates a new node of type stack_t
_push()	Pushes an element to the stack
_pall()	Prints all the elements of the stack
free_dlistint()	Frees a doubly linked list
_pint()	Prints the value at the top of the stack
_swap()	Swaps the top two elements of the stack
_pop()	Removes the top element of the stack
_add()	Adds the top two elements of the stack
_sub()	Subtracts the top element of the stack from the second
_nop()	Does nothing
cleanStack()	Cleans up the stack in case of an error
handle_command()	Handles the commands in the bytecode file
Error Handling

    monty.h: Header file containing function prototypes, structs and libraries.
    monty.c: Entry point for the program. Reads the contents of the file passed as an argument and executes the commands.
    function1.c: Contains functions for push, pall, pint, free_dlistint and new_Node.
    function2.c: Contains functions for swap, pop, add, sub and nop.
!https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.softwaretestinghelp.com%2Fstack-in-cpp%2F&psig=AOvVaw2kn1eGsymog0vJlNdPkOLO&ust=1683889036356000&source=images&cd=vfe&ved=0CBEQjRxqFwoTCNC5traP7f4CFQAAAAAdAAAAABAR
--- 
## Requirements :


    Allowed editors: vi, vim, emacs
    All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic
    All your files should end with a new line
    A README.md file, at the root of the folder of the project is mandatory
    Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
    You allowed to use a maximum of one global variable
    No more than 5 functions per file
    You are allowed to use the C standard library
    The prototypes of all your functions should be included in your header file called monty.h
    Don’t forget to push your header file
    All your header files should be include guarded
    You are expected to do the tasks in the order shown in the project
---
## Compilation & Output :

To compile the project, use the following command:

$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
---
### Exemple :

push and pall :

julien@ubuntu:~/monty$ cat -e bytecodes/00.m

push 1$

push 2$

push 3$

pall$

julien@ubuntu:~/monty$ ./monty bytecodes/00.m

3

2

1

julien@ubuntu:~/monty$

---
### Test :

We strongly encourage you to work all together on a set of tests

./monty test.m 
