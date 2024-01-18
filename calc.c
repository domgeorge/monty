#include "monty.h"
void _add(stack_t **nodepointer, unsigned int line_number);
void _nop(stack_t **nodepointer, unsigned int line_number);
void _sub(stack_t **nodepointer, unsigned int line_number);
void _div(stack_t **nodepointer, unsigned int line_number);
void _mul(stack_t **nodepointer, unsigned int line_number);
/**
 * _add - Adds the top two elements of the stack
 * @nodepointer: nodepointer
 * @line_number: Int Line
 */
void _add(stack_t **nodepointer, unsigned int line_number)
{
stack_t *initial;
stack_t *latter;
int add;

if (*nodepointer == NULL || (*nodepointer)->next == NULL)
{
fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
fclose(env.repo);
free(env.payloader);
stackFree(*nodepointer);
exit(EXIT_FAILURE);
}
initial = *nodepointer;
latter = initial->next;
add = initial->n + latter->n;
latter->n = add;
*nodepointer = latter;
free(initial);
}
/**
 *_nop - code Func does nothing if all is as required
 *@nodepointer: nodepointer
 *@line_number: my conde func for Int line
 *Return: Null
 */
void _nop(stack_t **nodepointer, unsigned int line_number)
{
(void)line_number;
(void)nodepointer;
}
/**
 *_sub - code Func for the sustration
 *@nodepointer: nodepointer
 *@line_number: my conde func for Int line
 *Return: Null
 */
void _sub(stack_t **nodepointer, unsigned int line_number)
{
stack_t *reserved;
int x, hike;
reserved = *nodepointer;
for (hike = 0; reserved != NULL; hike++)
reserved = reserved->next;
if (hike < 2)
{
fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
fclose(env.repo);
free(env.payloader);
stackFree(*nodepointer);
exit(EXIT_FAILURE);
}
reserved = *nodepointer;
x = reserved->next->n - reserved->n;
reserved->next->n = x;
*nodepointer = reserved->next;
free(reserved);
}

/**
 * _div - code Func for the division
 *@nodepointer: nodepointer
 *@line_number: my conde func for Int line
 *Return: Null
 */
void _div(stack_t **nodepointer, unsigned int line_number)
{
stack_t *map;
int weight, reserved;

weight = 0;
map = *nodepointer;
while (map)
{
map = map->next;
weight++;
}
if (weight < 2)
{
fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
fclose(env.repo);
free(env.payloader);
stackFree(*nodepointer);
exit(EXIT_FAILURE);
}
map = *nodepointer;
if (map->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", line_number);
fclose(env.repo);
free(env.payloader);
stackFree(*nodepointer);
exit(EXIT_FAILURE);
}
reserved = map->next->n / map->n;
map->next->n = reserved;
*nodepointer = map->next;
free(map);
}


/**
 * _mul - my code function that  multiply the top two elem.
 * @nodepointer : nodepointer
 * @line_number: Int line
 * Return: Null
 */
void _mul(stack_t **nodepointer, unsigned int line_number)
{
stack_t *map;
int weight, reserved;
weight = 0;
map = *nodepointer;
while (map)
{
map = map->next;
weight++;
}
if (weight < 2)
{
fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
fclose(env.repo);
free(env.payloader);
stackFree(*nodepointer);
exit(EXIT_FAILURE);
}
map = *nodepointer;
reserved = map->next->n * map->n;
map->next->n = reserved;
*nodepointer = map->next;
free(map);
}

/*Obinna Dominic*/
