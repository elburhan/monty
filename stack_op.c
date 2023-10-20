#include "monty.h"

void multiply(stack_t **stack, unsigned int line_number)
{
    int result;
    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        more_errors(8, line_number, "mul");
    (*stack) = (*stack)->next;
    result = (*stack)->data * (*stack)->prev->data;
    (*stack)->data = result;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}

void modulo(stack_t **stack, unsigned int line_number)
{
    int result;
    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        more_errors(8, line_number, "mod");
    if ((*stack)->data == 0)
        more_errors(9, line_number);
    (*stack) = (*stack)->next;
    result = (*stack)->data % (*stack)->prev->data;
    (*stack)->data = result;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}
