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

void
waitpidtest(void)
{
    int  pid_1, status;

    printf(1, "waitpid test\n");

    pid_1 = fork();
    if(pid_1>0){
        printf(1,"current process %d is waiting for pid %d...\n",getpid(),pid_1);
        waitpid(pid_1,&status,0);
        printf(1,"now finish waiting\n");

    }
    if(pid_1 == 0){

        sleep(100);
        printf(1,"process %d exit\n",getpid());
        exit_status(1);
    }

    printf(1,"current process %d exit",getpid());
    exit();
}


int
main(void)
{
    forktest();
    waitpidtest();

    exit();
}