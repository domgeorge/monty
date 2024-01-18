#include "monty.h"
void errMgr(unsigned int line_number, stack_t **nodepointer);
void _push(stack_t **nodepointer, unsigned int line_number);
void _pint(stack_t **nodepointer, unsigned int line_number);
void _pop(stack_t **nodepointer, unsigned int line_number);
void _swap(stack_t **nodepointer, unsigned int line_number);

/**
 * errMgr - code to manage/handle errors
 * @line_number: Int line number where possibility can occur
 * @nodepointer: nodepointer
 */
void errMgr(unsigned int line_number, stack_t **nodepointer)
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
fclose(env.repo);
free(env.payloader);
if (*nodepointer != NULL)
{
stackFree(*nodepointer);
}

exit(EXIT_FAILURE);
}

/**
 * _push - code Function that adds node
 * @nodepointer: nodepointer
 * @line_number: Int line number where possibility can occur
 */
void _push(stack_t **nodepointer, unsigned int line_number)
{
size_t jan;
int yep;

if (!env.arg || !*env.arg)
{
if (*nodepointer == NULL)
{
return;
}

errMgr(line_number, nodepointer);
}

for (jan = (env.arg[0] == '-'); env.arg[jan]; ++jan)
{
if (!isdigit(env.arg[jan]))
{
errMgr(line_number, nodepointer);
}
}

yep = atoi(env.arg);

if (env.nofi == 0)
{
inNode(nodepointer, yep);
}
else
{
pop_queue(nodepointer, yep);
}
}

/**
 * _pint - code Function to print top
 * @nodepointer: nodepointer
 * @line_number: where possiblity can occure inlin int
 * Return: Null
 */
void _pint(stack_t **nodepointer, unsigned int line_number)
{
if (*nodepointer == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
fclose(env.repo);
free(env.payloader);
stackFree(*nodepointer);
exit(EXIT_FAILURE);
}
printf("%d\n", (*nodepointer)->n);
}
/**
 * _pop - code Function to  print top
 * @nodepointer: nodepointer
 * @line_number: where possiblity can occure inlin int
 * Return: Null
 */
void _pop(stack_t **nodepointer, unsigned int line_number)
{
stack_t *lib;

if (*nodepointer == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
fclose(env.repo);
free(env.payloader);
stackFree(*nodepointer);
exit(EXIT_FAILURE);
}
lib = *nodepointer;
*nodepointer = lib->next;
free(lib);
}
/**
 * _swap - code Function to  print top
 * @nodepointer: nodepointer
 * @line_number: where possiblity can occure inlin int
 * Return: Null
 */
void _swap(stack_t **nodepointer, unsigned int line_number)
{
stack_t *initial, *latter;
int camp;

if (*nodepointer == NULL || (*nodepointer)->next == NULL)
{
fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
fclose(env.repo);
free(env.payloader);
stackFree(*nodepointer);
exit(EXIT_FAILURE);
}

initial = *nodepointer;
latter = initial->next;
camp = initial->n;

initial->n = latter->n;
latter->n = camp;
}

/*Obinna Dominic*/
