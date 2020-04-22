//
// Created by papi on 4/21.
//

#include "types.h"
#include "stat.h"
#include "user.h"

#define N  5



void
forktest(void)
{
    int n, pid, status;

    printf(1, "fork test\n");

    for(n=0; n<N; n++){
        pid = fork();
        if(pid < 0)
            break;
        if (pid > 0) { // parent
            pid = wait(&status); // wait for child
            printf(1, "child pid: %d, exit status: %d\n", pid, status);
            if(pid < 0){
                printf(1, "wait stopped early\n");
                exit();
            }
        }
        if(pid == 0){
            sleep(100);
            exit_status(1); //exit normally
        }

    }

    printf(1, "fork test OK\n");
}

int
main(void)
{
    forktest();
    exit();
}