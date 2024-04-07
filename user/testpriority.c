//
// Created by sue on 2/28/24.
//
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "user.h"


int main(void) {
    int pid;
    // Fork a new process
    pid = fork();

    // Check if we're in the child process
    if(pid == 0) {
        printf("Child process: setting priority to 2\n");
        setPriority(2); // Set a higher priority (assuming lower numbers are higher priority)
        for(int i = 0; i < 3; i++) {
            printf("Child working\n");
            sleep(10); // Simulate some work
        }
        exit(0);
    } else if(pid > 0) {
        printf("Parent process: setting priority to 5\n");
        setPriority(5); // Set a lower priority
        for(int i = 0; i < 3; i++) {
            printf("Parent working\n");
            sleep(10); // Simulate some work
        }

        // Wait for the child to exit
        wait((int *) 0);
    } else {
        printf("fork failed\n");
    }

    exit(0);
}
