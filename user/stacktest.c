#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/syscall.h"
#include "user.h"

void alloc_on_stack() {
    char stack_memory[4096]; // Allocate one page on the stack
    stack_memory[0] = 1; // Use memory to ensure it's allocated
    printf("Stack memory[0] = %d\n", stack_memory[0]);
}

int main() {
    printf("Stack allocation test\n");
    alloc_on_stack();
    myPages(getpid()); // Assuming myPages is a syscall
    exit(0);
}
