#include "monty.h"

void do_nothing(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}

void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;
    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        more_errors(8, line_number, "swap");
    tmp = (*stack)->next;
    (*stack)->next = tmp->next;
    if (tmp->next != NULL)
        tmp->next->prev = *stack;
    tmp->next = *stack;
    (*stack)->prev = tmp;
    tmp->prev = NULL;
    *stack = tmp;
}

void add(stack_t **stack, unsigned int line_number)
{
    int sum;
    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        more_errors(8, line_number, "add");
    (*stack) = (*stack)->next;
    sum = (*stack)->data + (*stack)->prev->data;
    (*stack)->data = sum;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}

void subtract(stack_t **stack, unsigned int line_number)
{
    int result;
    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        more_errors(8, line_number, "sub");
    (*stack) = (*stack)->next;
    result = (*stack)->data - (*stack)->prev->data;
    (*stack)->data = result;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}

void divide(stack_t **stack, unsigned int line_number)
{
    int result;
    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        more_errors(8, line_number, "div");
    if ((*stack)->data == 0)
        more_errors(9, line_number);
    (*stack) = (*stack)->next;
    result = (*stack)->data / (*stack)->prev->data;
    (*stack)->data = result;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}
