# 0x19. C - Stacks, Queues - LIFO, FIFO (Monty Bytecode Interpreter)

This is a project to implement a Monty Bytecode interpreter. The Monty programming language is a scripting language that relies on a unique stack with specific instructions to manipulate it. This interpreter will process Monty bytecode files and execute the specified instructions.

## Monty Bytecode Files

Monty bytecode files usually have the `.m` extension. Each instruction is written on a separate line, and there can be any number of spaces before or after the opcode and its argument. Blank lines and any additional text after the opcode or its required argument are not considered.

Example Monty bytecode file (`bytecodes/000.m`):
```
push 0
push 1
push 2
push 3
pall
push 4
push 5
push 6
pall
```

## Opcodes

This interpreter supports the following opcodes:
- `push`: Pushes an integer onto the stack.
- `pall`: Prints all the values on the stack.
- `pop`: Removes the top element from the stack.
- `swap`: Swaps the top two elements of the stack.
- `add`: Adds the top two elements of the stack and replaces them with the result.
- `nop`: Does nothing.
- `stack`: Sets the format of the data to a stack (LIFO), which is the default.
- `queue`: Sets the format of the data to a queue (FIFO).

## Usage

To use the Monty Bytecode Interpreter, run the following command:

```
./monty file
```

- `file`: The path to the file containing Monty bytecode instructions.

If no file is provided or more than one argument is given, the program will print the following error message and exit with EXIT_FAILURE:
```
USAGE: monty file
```

If the specified file cannot be opened, the program will print an error message and exit with EXIT_FAILURE:
```
Error: Can't open file <file>
```

If the file contains an invalid instruction, the program will print an error message along with the line number where the error occurred and exit with EXIT_FAILURE:
```
L<line_number>: unknown instruction <opcode>
```

If the program encounters a `malloc` failure, it will print the following error message and exit with EXIT_FAILURE:
```
Error: malloc failed
```

## Switching Between Stack and Queue

When switching between stack and queue modes:
- The top of the stack becomes the front of the queue.
- The front of the queue becomes the top of the stack.

## Example

Here's an example of how to use the Monty Bytecode Interpreter:

```shell
$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
$ ./monty bytecodes/00.m
3
2
1
```

The interpreter processes the Monty bytecode instructions and performs the specified operations.

Enjoy using the Monty Bytecode Interpreter for your Monty programming needs!
