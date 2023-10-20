#include "monty.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    open_file(argv[1]);
    free_nodes();
    return (EXIT_SUCCESS);
}

stack_t *create_node(int n)
{
    stack_t *node = malloc(sizeof(stack_t));
    if (node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    node->next = NULL;
    node->prev = NULL;
    node->n = n;
    return (node);
}

void add_to_queue(stack_t **new_node)
{
    stack_t *tmp;
    if (new_node == NULL || *new_node == NULL)
    {
        fprintf(stderr, "Error: stack too short\n");
        exit(EXIT_FAILURE);
    }
    if (head == NULL)
    {
        head = *new_node;
        return;
    }
    tmp = head;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = *new_node;
    (*new_node)->prev = tmp;
}
