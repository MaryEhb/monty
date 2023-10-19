#include "monty.h"

/**
 * pint - pint
 * @
 *
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
