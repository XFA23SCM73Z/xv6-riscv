//
// Created by sue on 4/7/24.
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/syscall.h"
#include "user.h"

int main() {
    printf("Heap allocation test\n");
    char *memory = malloc(4096); // Allocate one page on the heap
    if(memory == 0) {
        printf("malloc failed\n");
        exit(1);
    }
    // Initialize memory to trigger page fault and actually allocate the page.
    memory[0] = 1;
    myPages(getpid()); // Assuming myPages is a syscall to print page table details
    free(memory);
    exit(0);
}
