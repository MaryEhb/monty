#include "monty.h"

stack_t *head = NULL;
/**
 * main - Entry Point.
 * @argc: Num of arg.
 * @argv: Array of arguments.
 * Return: 0 (Success)
 */
int main(int argc, char **argv)
{

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	read_file(argv[1]);
	free_list();

	return (0);
}
