#include "node.h"

#include <stdio.h>
#include <stdlib.h>

Node *node_create(int id, int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (!node) {
        perror("Failed to allocate memory for Node");
        return NULL;
    }

    node->id = id;
    node->value = value;
    node->next = NULL;

    return node;
}

void node_destroy(Node *node) {
    if (node) {
        free(node);
    }
}
