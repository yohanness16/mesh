#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "node.h"

static void test_node_lifecycle(void) {
    Node *node = node_create(101, 2024);
    assert(node != NULL);
    assert(node->id == 101);
    assert(node->value == 2024);
    assert(node->next == NULL);

    node_destroy(node);
    printf("PASS: test_node_lifecycle\n");
}

int main(void) {
    printf("Running tests...\n");
    test_node_lifecycle();
    printf("All tests passed!\n");
    return EXIT_SUCCESS;
}
