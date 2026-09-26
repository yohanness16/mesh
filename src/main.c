#include <stdio.h>
#include <signal.h>
#include <unistd.h>

#include "node.h"


static volatile sig_atomic_t running = 1;

void signal_handler(int signal) {
    running = 0;
}

int main(void) {
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);

    while(running) {
        printf("node is running \n");
        sleep(1);
        
    }
    if (running == 0) {
            printf("node is stopping \n");
    }
    return 0;

}