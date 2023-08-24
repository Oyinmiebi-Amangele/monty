# Monty Interpreter

`monty` is an interpreter for Monty ByteCodes files, a scripting language similar to Python.

## About the Monty Language

The Monty language contains specific instructions to manipulate data information using stacks or queues. Each instruction, called an opcode, is provided per line. Files containing Monty byte codes typically have the `.m` extension.

Example `file.m`:

```shell
$ cat file.m
# Pushing element to the stack
push 0
push 1
push 2
# Printing all elements
pall
push 3
push 4
pop
# Rotating the stack to the bottom
rotr
pall
rotl
# Setting FIFO
queue
push 5
# Setting LIFO
stack
push 5
$
```

## Technologies

- The interpreter is written in C language.
- C files are compiled using gcc.
- Tested on Ubuntu 14.04 LTS.

## Usage

To compile the files:
```shell
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
$
```

The synopsis of the interpreter is as follows:
```shell
$ ./monty [filename]
$
```

To run the interpreter:
```shell
$ ./monty file.m
2
1
0
0
3
2
1
$
```

## Features

### Opcodes

`monty` executes the following opcodes:

Opcode       | Description
------------ | -------------------------
push         | Pushes an element to the stack
pall         | Prints all values on the stack
pint         | Prints the value at the top of the stack
pop          | Removes the top element of the stack
swap         | Swaps the top two elements of the stack
queue        | Sets the data format to a queue (FIFO)
stack        | Sets the data format to a stack (LIFO)
nop          | Does nothing
add          | Adds the top two elements of the stack
sub          | Subtracts the top element from the second top element
mul          | Multiplies the second top element with the top element
div          | Divides the second top element by the top element
mod          | Computes the remainder of the division of two elements
pchar        | Prints the character at the top of the stack
pstr         | Prints the string starting at the top of the stack
rotl         | Rotates the stack to the top
rotr         | Rotates the stack to the bottom

Comments, indicated with #, are not executed by the interpreter.

## Return Value

When there are no errors, `monty` returns 0. Otherwise, it returns 1.

## Authors

This project was authored by:

- Amangele Oyinmiebi
- Mr Watt Watt
