#include "monty.h"
/**
 * _pall - Func prints stack info
 * @nodepointer: nodepointer
 * @line_number: Int line
 * Return: Null
 */
void _pall(stack_t **nodepointer, unsigned int line_number)
{
	stack_t *ph;
	(void)line_number;

	ph = *nodepointer;
	if (ph == NULL)
	{
		/* Stack is empty, handle accordingly*/
		return;
	}

	/* Continue with the loop to print stack values*/
	while (ph)
	{
		printf("%d\n", ph->n);
		ph = ph->next;
	}
}
