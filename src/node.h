#ifndef NODE_H
#define NODE_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/**
 * @brief Represents a single node.
 */
typedef struct Node {
    int id;
    int value;
    struct Node *next;
} Node;

/**
 * @brief Creates a new node with the specified ID and value.
 *
 * @param id Unique identifier for the node.
 * @param value Value stored in the node.
 * @return Pointer to the newly allocated Node, or NULL on allocation failure.
 */
Node *node_create(int id, int value);

/**
 * @brief Frees the memory allocated for a node.
 *
 * @param node Pointer to the node to destroy.
 */
void node_destroy(Node *node);

#endif /* NODE_H */
