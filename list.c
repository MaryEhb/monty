#include "monty.h"

/**
 * create_node - Creates node.
 * @n: n.
 * Return: pointer to node. else NULL.
 */

stack_t *create_node(int n)
{
	stack_t *node = malloc(sizeof(stack_t));

	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_list();
		exit(EXIT_FAILURE);
	}

	node->n = n;
	node->next = NULL;
	node->prev = NULL;

	return (node);
}

/**
 * free_list - Frees nodes in the stack.
 * Return: Nothing
 */

void free_list(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * push - Adds a node to the stack.
 * @new_node: Pointer to new node.
 * @n: n.
 */

void push(stack_t **new_node,  __attribute__((unused))unsigned int n)
{
	stack_t *tmp;

	if (!new_node || !(*new_node))
		exit(EXIT_FAILURE);

	if (!head)
	{
		head = *new_node;
		return;
	}

	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}

/**
 * push_queue - push_queue
 * @new_node: node
 * @n: n
 * Return: NOthing
 */

void push_queue(stack_t **new_node,  __attribute__((unused))unsigned int n)
{
	stack_t *tmp;

	if (!new_node || !(*new_node))
		exit(EXIT_FAILURE);
	if (!head)
	{
		head = *new_node;
		return;
	}

	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *new_node;
	(*new_node)->prev = tmp;
}

/**
 * printall - print
 * @stack: Pointer to stack
 * @n: n
 * Return: Nothing
 */

void printall(stack_t **stack, unsigned int n)
{
	stack_t *tmp;

	(void) n;
	if (!stack)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
