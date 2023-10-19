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
