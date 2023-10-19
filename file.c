#include "monty.h"

/**
 * read_file - rf
 * @fn: filename
 * Return: NOthing
 */

void read_file(char *fn)
{
	FILE *fd = fopen(fn, "r");
	int n = 1, format = 0;
	char buffer[10000];
	size_t len = 1000;

	if (!fn || !fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fn);
		free_list();
		exit(EXIT_FAILURE);
	}

	while (fgets(buffer, len, fd))
	{
		format = parse_line(buffer, n, format);
		n++;
	}

	fclose(fd);
}

/**
 * parse_line - parse_line
 * @buffer: buffer
 * @n: n
 * @format: stack or queue
 * Return: int format
 */

int parse_line(char *buffer, int n, int format)
{
	char *value, *opcode = strtok(buffer, "\n ");

	if (!opcode)
		return (format);
	value = strtok(NULL, "\n ");

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	get_func(opcode, value, n, format);
	return (format);

}

/**
 * get_func - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @n: line number
 * Return: Nothing
 */

void get_func(char *opcode, char *value, int n, int format)
{
	instruction_t func_list[] = {{"push", push}, {"pall", printall},
		{"pint", pint}, {"pop", pop}, {"swap", swap}, {"nop", nop},
		{"add", add_op}};
	int flag = 1, i = 0;

	if (opcode[0] == '#')
		return;
	while (i < 7)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_func(func_list[i].f, opcode, value, n, format);
			flag = 0;
		}
		i++;
	}

	if (flag)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", n, opcode);
		free_list();
		exit(EXIT_FAILURE);
	}
}

/**
 * call_func - Calls the required function.
 * @func: Pointer to function.
 * @opcode: opcode.
 * @value: value.
 * @n: n
 * @format: Format
 */

void call_func(op_func func, char *opcode, char *value, int n, int format)
{
	int flag = 1;
	stack_t *node;

	if (strcmp(opcode, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			flag = -1;
		}

		if (!value)
		{
			fprintf(stderr, "L%d: usage: push integer\n", n);
			free_list();
			exit(EXIT_FAILURE);
		}

		node = create_node(atoi(value) * flag);
		if (format == 0)
			func(&node, n);

	}
	else
		func(&head, n);
}
