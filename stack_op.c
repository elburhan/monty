#include "monty.h"

/**
 * mul_nodes - Multiplies the values of the top two elements on the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void mul_nodes(stack_t **stack, unsigned int line_number)
{
    int product;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        more_err(8, line_number, "mul");

    (*stack) = (*stack)->next;
    product = (*stack)->n * (*stack)->prev->n;
    (*stack)->n = product;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}

/**
 * mod_nodes - Computes the remainder of the division of the top two elements on the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void mod_nodes(stack_t **stack, unsigned int line_number)
{
    int remainder;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        more_err(8, line_number, "mod");

    if ((*stack)->n == 0)
        more_err(9, line_number);

    (*stack) = (*stack)->next;
    remainder = (*stack)->n % (*stack)->prev->n;
    (*stack)->n = remainder;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}
