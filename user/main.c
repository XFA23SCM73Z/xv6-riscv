#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    int fd = -1; // Undefined file descriptor (typically, valid FDs are >= 0)
    int result = close(fd);

    if(result < 0){
        printf("close(fd) failed: fd is undefined or invalid\n");
    }

    exit(0);
}
