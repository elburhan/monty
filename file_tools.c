#include "monty.h"

void open_file(char *file_name)
{
    FILE *file_descriptor = fopen(file_name, "r");
    if (file_name == NULL || file_descriptor == NULL)
        error(2, file_name);
    read_file(file_descriptor);
    fclose(file_descriptor);
}

void read_file(FILE *file_descriptor)
{
    int line_number, format = 0;
    char *buffer = NULL;
    size_t len = 0;
    for (line_number = 1; getline(&buffer, &len, file_descriptor) != -1; line_number++)
    {
        format = parse_line(buffer, line_number, format);
    }
    free(buffer);
}

int parse_line(char *buffer, int line_number, int format)
{
    char *opcode, *value;
    const char *delimiter = "\n ";
    if (buffer == NULL)
        error(4);
    opcode = strtok(buffer, delimiter);
    if (opcode == NULL)
        return format;
    value = strtok(NULL, delimiter);
    if (strcmp(opcode, "stack") == 0)
        return 0;
    if (strcmp(opcode, "queue") == 0)
        return 1;
    find_function(opcode, value, line_number, format);
    return format;
}

void find_function(char *opcode, char *value, int line_number, int format)
{
    int i;
    int flag;
    instruction_t function_list[] = {
        {"push", push_stack},
        {"pall", print_stack},
        {"pint", print_top},
        {"pop", pop_top},
        {"nop", do_nothing},
        {"swap", swap},
        {"add", add},
        {"sub", subtract},
        {"div", divide},
        {"mul", multiply},
        {"mod", modulo},
        {"pchar", print_char},
        {"pstr", print_string},
        {"rotl", rotate_left},
        {"rotr", rotate_right},
        {NULL, NULL}};
    if (opcode[0] == '#')
        return;
    for (flag = 1, i = 0; function_list[i].opcode != NULL; i++)
    {
        if (strcmp(opcode, function_list[i].opcode) == 0)
        {
            call_function(function_list[i].function, opcode, value, line_number, format);
            flag = 0;
        }
    }
    if (flag == 1)
        error(3, line_number, opcode);
}

void call_function(op_function function, char *opcode, char *value, int line_number, int format)
{
    stack_t *node;
    int flag;
    int i;
    flag = 1;
    if (strcmp(opcode, "push") == 0)
    {
        if (value != NULL && value[0] == '-')
        {
            value = value + 1;
            flag = -1;
        }
        if (value == NULL)
            error(5, line_number);
        for (i = 0; value[i] != '\0'; i++)
        {
            if (isdigit(value[i]) == 0)
                error(5, line_number);
        }
        node = create_node(atoi(value) * flag);
        if (format == 0)
            function(&node, line_number);
        if (format == 1)
            enqueue(&node, line_number);
    }
    else
        function(&head, line_number);
}
