#include "monty.h"
/**
 * stackFree - code Function
 * @nodepointer: nodepointer
 */
void stackFree(stack_t *nodepointer)
{
stack_t *reserved;

reserved = nodepointer;
while (nodepointer)
{
reserved = nodepointer->next;
free(nodepointer);
nodepointer = reserved;
}
}
