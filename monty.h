#ifndef MONTY_H
#define MONTY_H

#define MAX 100

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct montyInt - code for Env for Monty interpreter
 * @arg: value of arg
 * @repo: file that points to monty file
 * @payloader: line for payloader
 * @nofi: flag to change sta queue
 * Description: Thats values int the program for Monty interpreter
 */
typedef struct montyInt
{
	char *arg;
	FILE *repo;
	char *payloader;
	int nofi;
} montyInt_t;

extern montyInt_t env;

void _push(stack_t **nodepointer, unsigned int line_number);
void _pall(stack_t **nodepointer, unsigned int line_number);
void _pint(stack_t **nodepointer, unsigned int line_number);
void _pop(stack_t **nodepointer, unsigned int line_number);
void _swap(stack_t **nodepointer, unsigned int line_number);
void _add(stack_t **nodepointer, unsigned int line_number);
void _nop(stack_t **nodepointer, unsigned int line_number);
void _sub(stack_t **nodepointer, unsigned int line_number);
void _div(stack_t **nodepointer, unsigned int line_number);
void _mul(stack_t **nodepointer, unsigned int line_number);
void _mod(stack_t **nodepointer, unsigned int line_number);
void _pchar(stack_t **nodepointer, unsigned int line_number);
void _pstr(stack_t **nodepointer, unsigned int line_number);
void _rotr(stack_t **nodepointer,
		__attribute__((unused)) unsigned int line_number);
void _rotl(stack_t **nodepointer,
		__attribute__((unused)) unsigned int line_number);
void _stack(stack_t **nodepointer, unsigned int line_number);
void _queue(stack_t **nodepointer, unsigned int line_number);
int exec(char *payloader, stack_t **stack, unsigned int count, FILE *file);
void stackFree(stack_t *nodepointer);
void pop_queue(stack_t **nodepointer, int n);
void inNode(stack_t **nodepointer, int n);

#endif /*_MONTY_H*/
