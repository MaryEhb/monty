#include "monty.h"

/**
 * pint - pint
 * @stack: stack
 * @n: n
 * Return: NOthing
 */

void pint(stack_t **stack, unsigned int n)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", n);
		free_list();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}


/**
 * pop - pop
 * @stack: stack
 * @n: n
 * Return: Nothing
 */

void pop(stack_t **stack, unsigned int n)
{
	stack_t *tmp;

	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", n);
		free_list();
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);

}

/**
 * swap - swap
 * @stack: stack
 * @n: n
 * Return: Nothing
 */

void swap(stack_t **stack, unsigned int n)
{
	stack_t *tmp;

	if (!stack || !(*stack) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", n);
		free_list();
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
	

}

/**
 * nop - nop
 * @stack: stack
 * @n: n
 * Return: Nothing
 */

void nop(stack_t **stack, unsigned int n)
{
	return;
}
