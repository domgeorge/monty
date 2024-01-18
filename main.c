#define _GNU_SOURCE
#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]);
montyInt_t env;

/**
 * main - interpreter
 * @argc: argument numbers
 * @argv: file location
 * Return: 0
 */
int main(int argc, char *argv[])
{
char *payloader;
FILE *repo;
size_t size_file = 0;
ssize_t init_line = 1;
stack_t *stack = NULL;
unsigned int num_ln = 0;

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
repo = fopen(argv[1], "r");
env.repo = repo;
if (!repo)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
while (init_line > 0)
{
payloader = NULL;
init_line = getline(&payloader, &size_file, repo);
env.payloader = payloader;
num_ln++;
if (init_line > 0)
{
exec(payloader, &stack, num_ln, repo);
}
free(payloader);
}
stackFree(stack);
fclose(repo);
return (0);
}
