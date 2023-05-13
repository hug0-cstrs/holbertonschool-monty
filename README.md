![holberton](https://blog.holbertonschool.com/wp-content/uploads/2022/01/Capture-decran-2022-01-11-172847.png)
---
# C - Stacks, Queues - LIFO, FIFO
---
# Monty interpreter
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

### Representation of the Stack :
![push](http://www.sitesbay.com/data-structure/images/push-operation.gif) &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;
![pop](http://www.sitesbay.com/data-structure/images/pop-operation.gif)
### Representation of the Queue :
![enqueue](http://www.sitesbay.com/data-structure/images/queue-insert-item.gif) <br>
![dequeue](http://www.sitesbay.com/data-structure/images/queue-delete-item.gif)
|**Filename**|**Description**|
|:------|:------:|
|`calculte.c`|File containing function calculate|
|`free.c`|File which containing functions to handle frees|
|`handle.error.c`|File containing functions to handle errors|
|`help.c`|File containing isdigit function|
|`monty.C`|Entry point for the program. Reads the contents of the file passed as an argument and executes the commands|
|`monty.h`|Header file containing function prototypes, structs and libraries.t|
|`opcode_struct.c`|File containing struct get_opc|
|`print_opcode.C`|File containing function pall and _pint|
|`rotate.c`|file containing the _rolt and _rort functions that allow to run the stack|
|`stack_op.c`|File content function _push _swap _pop _nop new_Node|

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

`gcc -Wall -Werror -Wextra -pedantic *.c -o monty`
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
### Author :

* **[Hugo Castéras](https://github.com/hug0-cstrs)**

* **[Alexis Grandjean](https://github.com/sixen31)**
