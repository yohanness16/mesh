#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>

#include "node.h"

#define NODE_ID_FILE "node.id"
#define NODE_ID_LEN 64

static volatile sig_atomic_t running = 1;

void signal_handler(int sig) {
    (void)sig;
    running = 0;
}

static void get_or_create_node_id(char *id, size_t max_len) {
    FILE *file = fopen(NODE_ID_FILE, "r");
    if (file) {
        if (fgets(id, (int)max_len, file)) {
            id[strcspn(id, "\r\n")] = '\0';
            if (id[0] != '\0') {
                fclose(file);
                printf("Found existing node ID: %s\n", id);
                return;
            }
        }
        fclose(file);
    }

    
    unsigned char b[16];
    FILE *urandom = fopen("/dev/urandom", "rb");
    if (urandom && fread(b, 1, sizeof(b), urandom) == sizeof(b)) {
        fclose(urandom);
    } else {
        if (urandom) fclose(urandom);
        srand((unsigned int)(time(NULL) ^ getpid()));
        for (int i = 0; i < 16; i++) {
            b[i] = (unsigned char)(rand() % 256);
        }
    }

   
    b[6] = (b[6] & 0x0f) | 0x40;
    b[8] = (b[8] & 0x3f) | 0x80;
    snprintf(id, max_len,
             "%02x%02x%02x%02x-%02x%02x-%02x%02x-%02x%02x-%02x%02x%02x%02x%02x%02x",
             b[0], b[1], b[2], b[3],
             b[4], b[5],
             b[6], b[7],
             b[8], b[9],
             b[10], b[11], b[12], b[13], b[14], b[15]);

    file = fopen(NODE_ID_FILE, "w");
    if (file) {
        fprintf(file, "%s\n", id);
        fclose(file);
        printf("Generated new node ID: %s\n", id);
    } else {
        perror("Failed to create node.id file");
    }
}

int main(void) {
    char node_id[NODE_ID_LEN] = {0};
    get_or_create_node_id(node_id, sizeof(node_id));

    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);

    while (running) {
        printf("node [%s] is running \n", node_id);
        sleep(1);
    }

    if (running == 0) {
        printf("node is stopping \n");
    }

    return 0;
}