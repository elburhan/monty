#include "monty.h"

void push_stack(stack_t **stack, unsigned int line_number)
{
    stack_t *new_node;
    if (stack == NULL)
    {
        fprintf(stderr, "Error: stack missing\n");
        exit(EXIT_FAILURE);
    }
    new_node = create_node(line_number);
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = line_number;
    if (*stack == NULL)
        *stack = new_node;
    else
    {
        new_node->next = *stack;
        (*stack)->prev = new_node;
        *stack = new_node;
    }
}

void print_stack(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;
    (void)line_number;
    if (stack == NULL || *stack == NULL)
    {
        fprintf(stderr, "Error: can't print, stack empty\n");
        exit(EXIT_FAILURE);
    }
    tmp = *stack;
    while (tmp != NULL)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
}
