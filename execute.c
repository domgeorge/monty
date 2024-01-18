#include "monty.h"

int exec(char *payloader, stack_t **stack, unsigned int line_number, FILE *repo);
/**
 * exec - code function that execute the entire program
 * @stack: Stack
 * @line_number: Intiger line
 * @repo: for the monty program file
 * @payloader: pointer to payloader
 * Return: Null(always else)
 */
int exec(char *payloader, stack_t **stack, unsigned int line_number, FILE *repo)
{
instruction_t OPT[] = {
{"push", _push},
{"pall", _pall},
{"pint", _pint},
{"pop", _pop},
{"swap", _swap},
{"add", _add},
{"nop", _nop},
{"sub", _sub},
{"div", _div},
{"mul", _mul},
{"mod", _mod},
{"pchar", _pchar},
{"pstr", _pstr},
{"rotl", _rotl},
{"rotr", _rotr},
{"queue", _queue},
{"stack", _stack},
{NULL, NULL},
};
unsigned int k = 0;
char *alx;

alx = strtok(payloader, " \n\t");
if (alx && alx[0] == '#')
return (0);
env.arg = strtok(NULL, " \n\t");
while (OPT[k].opcode && alx)
{
if (strcmp(alx, OPT[k].opcode) == 0)
{
OPT[k].f(stack, line_number);
return (0);
}
k++;
}
if (alx && OPT[k].opcode == NULL)
{
fprintf(stderr, "L%d: unknown instruction %s\n", line_number, alx);
fclose(repo);
free(payloader);
stackFree(*stack);
exit(EXIT_FAILURE);
}
return (1);
}
/*Obinna Dominic*/
