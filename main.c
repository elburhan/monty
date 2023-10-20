#include "monty.h"
stack_t *head = NULL;

/**
 * main - The main entry point of the program.
 * @argc: The count of command-line arguments.
 * @argv: An array of command-line argument strings.
 * Return: Always returns 0.
 */

int main(int argc, char *argv[])
{
        if (argc != 2)
        {
                fprintf(stderr, "USAGE: monty file\n");
                exit(EXIT_FAILURE);
        }
        open_file(argv[1]);
        free_nodes();
        return (0);
}

/**
 * create_node - Creates a new stack node.
 * @n: The integer value to be stored in the node.
 * Return: On success, returns a pointer to the new node; otherwise, returns NULL.
 */
stack_t *create_node(int n)
{
        stack_t *node;

        node = malloc(sizeof(stack_t));
        if (node == NULL)
                err(4);
        node->next = NULL;
        node->prev = NULL;
        node->n = n;
        return (node);
}

/**
 * free_nodes - Frees all nodes in the stack.
 */
void free_nodes(void)
{
        stack_t *tmp;

        if (head == NULL)
                return;

        while (head != NULL)
        {
                tmp = head;
                head = head->next;
                free(tmp);
        }
}


/**
 * add_to_queue - Adds a new node to the queue.
 * @new_node: A pointer to the new node to be added.
 * @ln: Line number of the opcode (unused attribute).
 */
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
        stack_t *tmp;

        if (new_node == NULL || *new_node == NULL)
                exit(EXIT_FAILURE);
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
