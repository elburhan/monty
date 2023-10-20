#include "monty.h"

/**
 * err - Prints appropriate error messages based on error codes.
 * @error_code: The error codes are as follows:
 * (1) => The user did not provide a file or provided more than one file.
 * (2) => The specified file cannot be opened or read.
 * (3) => The provided file contains an invalid instruction.
 * (4) => Memory allocation (malloc) has failed.
 * (5) => The "push" instruction received a non-integer parameter.
 * (6) => The stack is empty when executing "pint."
 * (7) => The stack is empty when executing "pop."
 * (8) => The stack is too short for a particular operation.
 */
void err(int error_code, ...)
{
        va_list args;
        char *opcode;
        int line_number;

        va_start(args, error_code);
        switch (error_code)
        {
                case 1:
                        fprintf(stderr, "USAGE: monty file\n");
                        break;
                case 2:
                        fprintf(stderr, "Error: Can't open file %s\n", va_arg(args, char *));
                        break;
                case 3:
                        line_number = va_arg(args, int);
                        opcode = va_arg(args, char *);
                        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
                        break;
                case 4:
                        fprintf(stderr, "Error: memory allocation (malloc) failed\n");
                        break;
                case 5:
                        fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
                        break;
                default:
                        break;
        }
        free_nodes();
        exit(EXIT_FAILURE);
}

/**
 * more_err - Handles additional errors.
 * @error_code: The error codes are as follows:
 * (6) => The stack is empty when executing "pint."
 * (7) => The stack is empty when executing "pop."
 * (8) => The stack is too short for a particular operation.
 * (9) => Division by zero.
 */
void more_err(int error_code, ...)
{
        va_list args;
        char *opcode;
        int line_number;

        va_start(args, error_code);
        switch (error_code)
        {
                case 6:
                        fprintf(stderr, "L%d: can't pint, stack is empty\n", va_arg(args, int));
                        break;
                case 7:
                        fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(args, int));
                        break;
                case 8:
                        line_number = va_arg(args, unsigned int);
                        opcode = va_arg(args, char *);
                        fprintf(stderr, "L%d: can't %s, stack is too short\n", line_number, opcode);
                        break;
                case 9:
                        fprintf(stderr, "L%d: division by zero\n", va_arg(args, unsigned int));
                        break;
                default:
                        break;
        }
        free_nodes();
        exit(EXIT_FAILURE);
}

/**
 * string_err - Handles string-related errors.
 * @error_code: The error codes are as follows:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */
void string_err(int error_code, ...)
{
        va_list args;
        int line_number;

        va_start(args, error_code);
        line_number = va_arg(args, int);
        switch (error_code)
        {
                case 10:
                        fprintf(stderr, "L%d: can't pchar, value is out of range\n", line_number);
                        break;
                case 11:
                        fprintf(stderr, "L%d: can't pchar, the stack is empty\n", line_number);
                        break;
                default:
                        break;
        }
        free_nodes();
        exit(EXIT_FAILURE);
}
