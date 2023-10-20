#include "monty.h"

void print_char(stack_t **stack, unsigned int line_number)
{
    int ascii;
    if (stack == NULL || *stack == NULL)
    {
        fprintf(stderr, "Error: can't pchar, stack empty\n");
        exit(EXIT_FAILURE);
    }
    ascii = (*stack)->n;
    if (ascii < 0 || ascii > 127)
    {
        fprintf(stderr, "Error: can't pchar, value out of range\n");
        exit(EXIT_FAILURE);
    }
    printf("%c\n", ascii);
}

void print_str(stack_t **stack, unsigned int line_number)
{
    int ascii;
    stack_t *tmp;
    (void)line_number;
    if (stack == NULL || *stack == NULL)
    {
        printf("\n");
        return;
    }
    tmp = *stack;
    while (tmp != NULL)
    {
        ascii = tmp->n;
        if (ascii <= 0 || ascii > 127)
            break;
        printf("%c", ascii);
        tmp = tmp->next;
    }
    printf("\n");
}
