#include "monty.h"

/**
 * handle_error - Handles and reports errors based on error code.
 * @error_code: The error code that indicates the type of error.
 * @line_number: The line number in the Monty script where the error occurred.
 * @op: The opcode that caused the error (if applicable).
 */
void handle_error(int error_code, unsigned int line_number, char *op)
{
    switch (error_code)
    {
        case 1:
            fprintf(stderr, "USAGE: monty file\n");
            break;
        case 2:
            fprintf(stderr, "Error: Can't open file %s\n", op);
            break;
        case 3:
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
            break;
        case 4:
            fprintf(stderr, "Error: malloc failed\n");
            break;
        case 5:
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            break;
        case 6:
            fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
            break;
        case 7:
            fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
            break;
        case 8:
            fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, op);
            break;
        case 9:
            fprintf(stderr, "L%d: division by zero\n", line_number);
            break;
        default:
            break;
    }
    free_nodes();
    exit(EXIT_FAILURE);
}

/**
 * free_nodes - Frees the memory of all nodes in the stack.
 */
void free_nodes(void)
{
    stack_t *current = head;

    while (current != NULL)
    {
        stack_t *temp = current;
        current = current->next;
        free(temp);
    }
}

/**
 * report_string_error - Handles and reports string-related errors.
 * @error_code: The error code that indicates the type of error.
 * @line_number: The line number in the Monty script where the error occurred.
 */
void report_string_error(int error_code, unsigned int line_number)
{
    switch (error_code)
    {
        case 10:
            fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
            break;
        case 11:
            fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
            break;
        default:
            break;
    }
    free_nodes();
    exit(EXIT_FAILURE);
}
