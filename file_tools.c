#include "monty.h"

/**
 * open_file - Opens a specified file.
 * @file_name: The file path to be opened.
 * Return: void
 */

void open_file(char *file_name)
{
        FILE *file_descriptor = fopen(file_name, "r");

        if (file_name == NULL || file_descriptor == NULL)
                err(2, file_name);

        read_file(file_descriptor);
        fclose(file_descriptor);
}


/**
 * read_file - Reads lines from a file.
 * @fd: Pointer to a file descriptor.
 * Return: void
 */

void read_file(FILE *fd)
{
        int line_number, format = 0;
        char *buffer = NULL;
        size_t buffer_size = 0;

        for (line_number = 1; getline(&buffer, &buffer_size, fd) != -1; line_number++)
        {
                format = parse_line(buffer, line_number, format);
        }
        free(buffer);
}


/**
 * parse_line - Separates each line into tokens to determine which function to call.
 * @buffer: Line from the file.
 * @line_number: Line number.
 * @format: Storage format. If 0, nodes will be treated as a stack; if 1, as a queue.
 * Return: Returns 0 if the opcode is "stack," 1 if "queue."
 */

int parse_line(char *buffer, int line_number, int format)
{
        char *opcode, *value;
        const char *delimiter = "\n ";

        if (buffer == NULL)
                err(4);

        opcode = strtok(buffer, delimiter);
        if (opcode == NULL)
                return format;
        value = strtok(NULL, delimiter);

        if (strcmp(opcode, "stack") == 0)
                return 0;
        if (strcmp(opcode, "queue") == 0)
                return 1;

        find_func(opcode, value, line_number, format);
        return format;
}

/**
 * find_func - Finds the appropriate function for the given opcode.
 * @opcode: Opcode.
 * @value: Argument of the opcode.
 * @ln: Line number.
 * @format: Storage format. If 0, nodes will be treated as a stack; if 1, as a queue.
 * Return: void
 */

void find_func(char *opcode, char *value, int ln, int format)
{
        int i;
        int flag;

        instruction_t func_list[] = {
                {"push", add_to_stack},
                {"pall", print_stack},
                {"pint", print_top},
                {"pop", pop_top},
                {"nop", nop},
                {"swap", swap_nodes},
                {"add", add_nodes},
                {"sub", sub_nodes},
                {"div", div_nodes},
                {"mul", mul_nodes},
                {"mod", mod_nodes},
                {"pchar", print_char},
                {"pstr", print_str},
                {"rotl", rotl},
                {"rotr", rotr},
                {NULL, NULL}
        };

        if (opcode[0] == '#')
                return;

        for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
        {
                if (strcmp(opcode, func_list[i].opcode) == 0)
                {
                        call_fun(func_list[i].f, opcode, value, ln, format);
                        flag = 0;
                }
        }
        if (flag == 1)
                err(3, ln, opcode);
}


/**
 * call_fun - Calls the required function.
 * @func: Pointer to the function to be called.
 * @op: String representing the opcode.
 * @val: String representing a numeric value.
 * @ln: Line number for the instruction.
 * @format: Storage format. If 0, nodes are treated as a stack; if 1, as a queue.
 */

void call_fun(op_func func, char *op, char *val, int ln, int format)
{
        stack_t *node;
        int flag;
        int i;

        flag = 1;
        if (strcmp(op, "push") == 0)
        {
                if (val != NULL && val[0] == '-')
                {
                        val = val + 1;
                        flag = -1;
                }
                if (val == NULL)
                        err(5, ln);
                for (i = 0; val[i] != '\0'; i++)
                {
                        if (isdigit(val[i]) == 0)
                                err(5, ln);
                }
                node = create_node(atoi(val) * flag);
                if (format == 0)
                        func(&node, ln);
                if (format == 1)
                        add_to_queue(&node, ln);
        }
        else
                func(&head, ln);
}
