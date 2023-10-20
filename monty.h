#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

typedef struct stack_s
{
    int data;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
    char *opcode;
    void (*function)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_function)(stack_t **, unsigned int);

void open_file(char *file_name);
int parse_line(char *line, int line_number, int format);
void read_file(FILE *file);
int line_length(FILE *file);
void find_function(char *opcode, char *argument, int line_number, int format);

stack_t *create_node(int data);
void free_nodes(void);
void print_stack(stack_t **stack, unsigned int line_number);
void push_stack(stack_t **stack, unsigned int line_number);
void enqueue(stack_t **stack, unsigned int line_number);

void call_function(op_function function, char *opcode, char *argument, int line_number, int format);

void print_top(stack_t **stack, unsigned int line_number);
void pop_top(stack_t **stack, unsigned int line_number);
void do_nothing(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

void add(stack_t **stack, unsigned int line_number);
void subtract(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void multiply(stack_t **stack, unsigned int line_number);
void modulo(stack_t **stack, unsigned int line_number);

void print_char(stack_t **stack, unsigned int line_number);
void print_string(stack_t **stack, unsigned int line_number);
void rotate_left(stack_t **stack, unsigned int line_number);
void rotate_right(stack_t **stack, unsigned int line_number);

void error(int error_code, ...);
void more_errors(int error_code, ...);
void string_error(int error_code, ...);

#endif
